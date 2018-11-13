clear all;
close all;
clc;

alpha=0.5; %Parámetro de la ventana de Hamming
NFFT=256; %Número de puntos de la FFT
delta=160; %Traslape
Lwin=400; %Tamaño de ventana
Nfiltros = 20;

[yy,Fs]=audioread('perro.wav');
yy=yy';
yy=yy/max(yy);
[evolucionUmbral]=AnalisisUmbral(yy);
[palabradelimitada, longPal]=detectorExtremos(yy);
y1=palabradelimitada;
% figure(2);
% subplot(2,1,1);
% plot(yy);
% subplot(2,1,2);
% plot(y1);

%%
%y1=yy(1,6400:15000); %eliminación manual de silencios
y=filter([1,-0.95],1,y1); %Filtro de preenfasis y(n)= y1(n)-0.95*y1(n-1);
n=0:Lwin-1;
W=(1-alpha)-alpha*cos(2*pi*n/Lwin); %Ventana de Hamming

%Frecuencias de Mel
f1=300; %Frecuencia en Hz inicial
fmel1=1125*log(1+f1/700); %Frecuencia de
f2=Fs/2; %Frecuencia en Hz final
fmel2=1125*log(1+f2/700);
deltamel=(fmel2-fmel1)/(Nfiltros+1);
fmel=fmel1:deltamel:fmel2;
f_Hz=700*(exp(fmel/1125)-1); %Vector de frecuencias en Hz
f_norm=floor((NFFT+1)*f_Hz/Fs); %Vector de frecuencias discretas: 1->NFFT

%%
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
%     subplot(2,1,1);
%     plot(0:NFFT/2-1,Hm(m,:));
%     hold on;
%     title('Banco de filtros de Mel');
%     xlabel('Puntos');
%     
%     subplot(2,1,2);
%     plot(0:Fs/NFFT:Fs/2-Fs/NFFT,Hm(m,:));
%     hold on;
%     title('Banco de filtros de Mel');
%     xlabel('Hz');
end

%%
%Rutina para entramado, FFT, energía, MFCC
n=0;
ntrama=0;
tramaVoz=[];
while(n+Lwin)<length(y)
    tramaVoz=y(n+1:n+Lwin); %Entramado
    tramaVoz=tramaVoz.*W; %Ventaneo
    tramaEspectral=fft(tramaVoz,NFFT); %T. de Fourier de la trama
    tramaEspectral2=tramaEspectral(1:NFFT/2); %Solo consideramos la mitad de puntos del espectro ya que es simétrico
    for k=2:Nfiltros+1
        tramaEspecFil(k,:)= tramaEspectral2.*Hm(k,:); %Filtrado en frecuencia
        energia(ntrama+1,k)= sum(tramaEspecFil(k,:).*conj(tramaEspecFil(k,:))); %Obtención de la energía en cada banda
        temp=0;
        for l=1:Nfiltros
            temp= temp+(log(energia(ntrama+1,k))*cos(l*(k-0.5)*pi/Nfiltros)); %Obtención de los coeficientes cepstrales
        end %usando la DCT 
        MFCC(ntrama+1,k)=temp;
        %plot(abs(tramaEspecFil(k,:)));
        %pause;
    end
    n=n+delta;
    ntrama=ntrama+1;
    %plot(abs(tramaEspectral));
    %pause;
end
%% 
[r, c]=size(MFCC)
diferenciaRows=50-r;
diferenciaCol=25-c;
b=padarray(MFCC,[diferenciaRows diferenciaCol],0,'post')
size(b)
b(isnan(b))=0;
