clc;
close all;
clear all;

%% Escrbimos y leemos los coeficientes/opcional
% dlmwrite('iirb1.txt', Num, 'delimiter', ',', 'precision', 30); 
% dlmwrite('iira1.txt', Den, 'delimiter', ',', 'precision', 30);
% dlmwrite('iirb2.txt', Num1, 'delimiter', ',', 'precision', 30);
% dlmwrite('iira2.txt', Den1, 'delimiter', ',', 'precision', 30);

b1=dlmread('iirb1.txt'); 
a1=dlmread('iira1.txt');
b2=dlmread('iirb2.txt'); 
a2=dlmread('iira2.txt');
% a1=dlmread('iirb1.txt'); 
% b1=dlmread('iira1.txt');
% a2=dlmread('iirb2.txt'); 
% b2=dlmread('iira2.txt');

%% Filtrejae FIR con procesamiento por muestra
[inputSample, Fs]=audioread('elpasofs16000Nb16_3.wav');
inputSample=inputSample(1:240000);
Na=length(b1);
Nx=length(inputSample);
yy=filter(b1,a1,inputSample);
u=zeros(1,Na);
yv=[];

%% Filtraje por muestras para banda de 500
for n=1:Nx
    x(1)=inputSample(n);
    tempa=0;
    tempb=0;
    
    y=0;
    for k=2:Na
        tempa=tempa-a1(k)*u(k);
        tempb=tempb+b1(k)*u(k);
    end
    
    u(1)=x(1)+tempa;
    y=u(1)*b1(1)+tempb;
    yv=[yv y];
    
    for m=Na:-1:2
        u(m)=u(m-1);
    end
end
%% Filtraje por muestras para banda de 1000
inputSample=yv;
Na=length(b2);
Nx=length(inputSample);
yyy=filter(b2,a2,yy);
u=zeros(1,Na);
yv=[];

for n=1:Nx
    x(1)=inputSample(n);
    tempa=0;
    tempb=0;
    
    y=0;
    for k=2:Na
        tempa=tempa-a2(k)*u(k);
        tempb=tempb+b2(k)*u(k);
    end
    
    u(1)=x(1)+tempa;
    y=u(1)*b2(1)+tempb;
    yv=[yv y];
    
    for m=Na:-1:2
        u(m)=u(m-1);
    end
end

%%
sound(yv, Fs);


%% Graficas
figure(1);
[x, Fs]=audioread('elpasofs16000Nb16_3.wav');
x=x';
n=0:1/Fs:length(x)/Fs-1/Fs;
subplot(2,1,1);
plot(n,x);
xlabel('$Segundos$','Interpreter','latex');
ylabel('$Amplitud$','Interpreter','latex');
title('Señal en el tiempo: el paso del gigante');
axis([0 205 -.6 .6]);
grid on;

[X,W]=freqz(x,1);
subplot(2,1,2);
plot(W*Fs/(2*pi),abs(X));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

figure(2);
subplot(2,1,1);
plot(yv);
xlabel('$Segundos$','Interpreter','latex');
ylabel('$Amplitud$','Interpreter','latex');
title('Señal en el tiempo: el paso del gigante');
grid on;

[Y,W]=freqz(yv,1);
subplot(2,1,2);
plot(W*Fs/(2*pi),abs(Y));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

%% Muestra depues de filtraje
sound(yv, Fs);