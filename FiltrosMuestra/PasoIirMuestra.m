clc;
close all;
clear all;

%% Escrbimos y leemos los coeficientes/opcional
% dlmwrite('iirb1.txt', Num, 'delimiter', ',', 'precision', 30); 
% dlmwrite('iira1.txt', Den, 'delimiter', ',', 'precision', 30);
b1=dlmread('iirb1.txt'); 
a1=dlmread('iira1.txt');

%% Filtrejae FIR con procesamiento por muestra
[inputSample, Fs]=audioread('elpasofs16000Nb16_3.wav');
Na=length(b1);
Nx=length(inputSample);
yy=filter(b1,a1,inputSample);
u=zeros(1,Na);
yv=zeros(1,Na);

%% Filtraje por muestras 
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
    yv(n)=y;
    
    for m=Na:-1:2
        u(m)=u(m-1);
    end
end

%% Graficas
figure(1);
x=inputSample';
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
axis([0 3.3e6 -.6 .6]);
grid on;

[Y,W]=freqz(yv,1);
subplot(2,1,2);
plot(W*Fs/(2*pi),abs(Y));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

%% Muestra depues de filtraje
sound(yv(1:160000), Fs);

