clear all;
close all;
clc;

%% Audios de misma longitud

[yy,Fs]=audioread('ro.wav'); 
yy=yy';
figure(1);
plot(yy);

y1=yy(1,2500:5500); %eliminación manual de silencios
figure(2);
plot(y1);

[yy,Fs]=audioread('ro.wav');
yy=yy';
yy=yy/max(yy);
[palabradelimitada, longPal]=detectorExtremos(yy);
y1=palabradelimitada;
figure(3);
plot(y1);


%% Variables definidas
alpha=0.5; %Parámetro de la ventana de Hamming
NFFT=256; %Número de puntos de la FFT
delta=160; %Traslape
Lwin=400; %Tamaño de ventana
Nfiltros = 20;