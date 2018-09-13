%% 
clc;
close all;
clear all;

%% Graficas de audio original
figure(1);
[x,Fs]=audioread('elpasofs16000Nb16_3.wav');
x=x';
n=0:1/Fs:length(x)/Fs-1/Fs;
subplot(3,1,1);
plot(n,x);
xlabel('$Segundos$','Interpreter','latex');
ylabel('$Amplitud$','Interpreter','latex');
title('Señal en el tiempo: el paso del gigante');
axis([0 205 -.6 .6]);
grid on;

%X=fftshift(fft(x,length(x)));
%F2=-Fs/2:Fs/length(X):Fs/2-Fs/length(X);
%subplot(2,1,2)
%plot(F2,abs(X));
[X,W]=freqz(x,1);
subplot(3,1,2);
plot(W*Fs/(2*pi),abs(X));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

X=fftshift(fft(x,length(x)));
F2=-Fs/2:Fs/length(X):Fs/2-Fs/length(X);
subplot(3,1,3)
plot(F2,abs(X));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
axis([-1000 1000 0 8e4]);
grid on;

%% Escrbimos y leemos los coeficientes de la funcion de tranferencia/opcional
%dlmwrite('firCoeficientes1.txt', h1, 'delimiter', ',', 'precision', 30); 
hb1=dlmread('firCoeficientes1.txt'); 
%dlmwrite('firCoeficientes2.txt', h2, 'delimiter', ',', 'precision', 30); 
hb2=dlmread('firCoeficientes2.txt');

%% Aplicacion de filtro
yb1=conv(hb1,x);
y=conv(hb2,yb1);
sound(y,Fs);

%% Graficas despues de filtro
figure(2);
subplot(3,1,1);
plot(y);
xlabel('$Segundos$','Interpreter','latex');
ylabel('$Amplitud$','Interpreter','latex');
title('Señal en el tiempo: el paso del gigante');
grid on;

[Y,W]=freqz(y,1);
subplot(3,1,2);
plot(W*Fs/(2*pi),abs(Y));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

Y=fftshift(fft(y,length(y)));
F2=-Fs/2:Fs/length(Y):Fs/2-Fs/length(Y);
subplot(3,1,3)
plot(F2,abs(Y));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;
