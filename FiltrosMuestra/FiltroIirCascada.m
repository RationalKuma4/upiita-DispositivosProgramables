clear all;
close all;
clc;

%% Escrbimos y leemos los coeficientes/opcional
%dlmwrite('cacadab1.txt', Num, 'delimiter', ',', 'precision', 30);
%dlmwrite('cascada1.txt', Den, 'delimiter', ',', 'precision', 30);
b=dlmread('cacadab1.txt');
a=dlmread('cascada1.txt');

%% Iniciamos el filtraje IIR por muestra
[inputSample, Fs]=audioread('elpasofs16000Nb16_3.wav');
%inputSample=inputSample(1:10);
Na=length(a);
Nx=length(inputSample);
yy=filter(b,a,inputSample);
u=zeros(1,Na);
yv=zeros(1,Na);
for n=1:Nx
    x(1)=inputSample(n);
    tempa=0;
    tempb=0;
    
    for k=2:Na
        tempa=tempa-a(k)*u(k);
        tempb=tempb+b(k)*u(k);
    end
    
    u(1)=x(1)+tempa;
    y=u(1)*b(1)+tempb;
    yv(n)=y;
    
    for m=Na:-1:2
        u(m)=u(m-1);
    end
    %yy
    %ye
    %pause
end
% Prueba de audio
%sound(yv(1:160000), Fs);

%% Escrbimos y leemos la matriz y ganancia
%dlmwrite('ganancia.txt', G, 'delimiter', ',', 'precision', 30);
%dlmwrite('matriz.txt', SOS, 'delimiter', ',', 'precision', 30);
G=dlmread('ganancia.txt');
SOS=dlmread('matriz.txt');

%% Iniciamos el filtraje IIR en cascada
disp('Filtraje en cascada')
Ne=4;
gg=G';
bb=SOS(1:4,1:3);
aa=SOS(1:4,4:6);
uu=zeros(Ne,3);
yv=zeros(1,Na);

for n=1:Nx
    x(1)=inputSample(n);
    for e=1:Ne
        temp1=0;
        temp2=0;
        
        for k=2:3
            temp1=temp1-aa(e,k)*uu(e,k);
            temp2=temp2+bb(e,k)*uu(e,k);
        end
        
        uu(e,1)=gg(e)*x+temp1;
        ye=uu(e,1)*bb(e,1)+temp2;
        yv(n)=ye;
        for m=3:-1:2
            uu(e,m)=uu(e,m-1);
        end
        x=ye;
    end
    %yy
    %ye
    %pause
end
% Prueba de audio
sound(yv(1:160000), Fs);

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
