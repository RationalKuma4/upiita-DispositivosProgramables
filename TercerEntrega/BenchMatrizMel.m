close all;
clear all;
clc;

[bro,Fs] = audioread('bro.wav');

yy=bro';
yy=yy/max(yy);
[palabradelimitada]=detectorExtremos(yy);
y1=palabradelimitada;

alpha=0.5; %Parámetro de la ventana de Hamming
NFFT=256; %Número de puntos de la FFT
delta=160; %Traslape
Lwin=400; %Tamaño de ventana
Nfiltros = 20;

%y=filter([1,-0.95],1,y1); %Filtro de preenfasis
%n=2:Lwin+1; %yyy(n)= y1(n)-0.95*y1(n-1);
%W=(1-alpha)-alpha*cos(2*pi*n/Lwin); %Ventana de Hamming

%Frecuencias de Mel
f1=300; %Frecuencia en Hz inicial
fmel1=1125*log(1+f1/700); %Frecuencia de
f2=Fs/2; %Frecuencia en Hz final
fmel2=1125*log(double(1+f2/700));
deltamel=(fmel2-fmel1)/(Nfiltros+1);
fmel=fmel1:deltamel:fmel2;
f_Hz=700*(exp(fmel/1125)-1); %Vector de frecuencias en Hz
f_norm=floor((NFFT+1)*double(f_Hz)/double(Fs)); %Vector de frecuencias discretas: 1->NFFT

%Obtención del banco de filtros de Mel
% figure(1);
Hm=zeros(Nfiltros,NFFT/2);
for m=2:Nfiltros+1
    for k=1:NFFT/2
        if k < f_norm(m-1)
            Hm(m,k) = 0;
        elseif f_norm(m-1)<=k && k<=f_norm(m)
            Hm(m,k) = (k - f_norm(m-1))/(f_norm(m) - f_norm(m-1));
        elseif f_norm(m)<=k && k<=f_norm(m+1)
            Hm(m,k) = (f_norm(m+1) - k)/(f_norm(m+1) - f_norm(m));
        elseif k>f_norm(m+1)
            Hm(m,k) = 0;
        end
    end
end