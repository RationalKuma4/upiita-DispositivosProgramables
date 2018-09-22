clc;
close all;
clear all;

%% Escrbimos y leemos los coeficientes de la funcion de tranferencia/opcional
%dlmwrite('firCoeficientes1.txt', h, 'delimiter', ',', 'precision', 30);
hb1=dlmread('firCoeficientes1.txt');

%% Filtrejae FIR con procesamiento por muestra
% guardar muestras de y
%h=[1 2 3 4]; % coeficientes del filtro
lh=length(hb1);
[inputSample, Fs]=audioread('elpasofs16000Nb16_3.wav');
Nx=length(inputSample);
yy=conv(hb1,inputSample);
x=zeros(1,Nx+lh-1);
yv=[];

%% Filtraje por muestras
for n=1:Nx+lh-1
    if(n<=Nx)
        x(1)=inputSample(n);
    else
        x(1)=0;
    end
    
    y=0;
    for k=1:lh
        y=y+hb1(k)*x(k);
        yv(n)=y;
    end
    
    for m=lh:-1:2
        x(m)=x(m-1);
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
axis([0 3.5e6 -.6 .6]);
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
