function [mfcc] = MatrizFreMel(y, Hm, W)
Lwin=400; %Tamaño de ventana
NFFT=256; %Número de puntos de la FFTNFFT=256; %Número de puntos de la FFT
delta=160; %Traslape
Nfiltros = 20;
%Rutina para entramado, FFT, energía, MFCC
n=0;
ntrama=0;
tramaVoz=[];
energia=zeros(48,21);
tramaEspecFil=zeros(21,128);
MFCC=zeros(48,21);

while(n+Lwin)<length(y)
    tramaVoz=y(n+1:n+Lwin); %Entramado
    tramaVoz=tramaVoz.*W; %Ventaneo
    tramaEspectral=fft(tramaVoz,NFFT); %T. de Fourier de la trama
    tramaEspectral2=tramaEspectral(1:NFFT/2); %Solo consideramos la mitad de puntos del espectro ya que es simétrico
    for k=2:Nfiltros+1
        tramaEspecFil(k,:)= real(tramaEspectral2.*Hm(k,:)); %Filtrado en frecuencia
        energia(ntrama+1,k)= sum(tramaEspecFil(k,:).*conj(tramaEspecFil(k,:))); %Obtención de la energía en cada banda
        temp=0;
        for l=1:Nfiltros
            temp= temp+(log(energia(ntrama+1,k))*cos(l*(k-0.5)*pi/Nfiltros)); %Obtención de los coeficientes cepstrales
        end %usando la DCT
        MFCC(ntrama+1,k)=temp;
    end
    n=n+delta;
    ntrama=ntrama+1;
end

[r, c]=size(MFCC);
diferenciaRows=50-r;
diferenciaCol=25-c;
b=padarray(MFCC,[diferenciaRows diferenciaCol],0,'post');
mfcc=b;
end

