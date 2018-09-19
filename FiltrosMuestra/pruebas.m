clc;
close all;
clear all;

%% Filtrejae IIR con procesamiento por muestra
% guardar muestras de y
a=[1,-7.66518063681231,25.8311620521211,-49.9830584908423,60.7382997125340,-47.4634352910318,23.2926275181552,-6.56355313674101,0.813139261401185];%den coeficientes del filtro
b=[0.901742347565181,-7.09538178661411,24.5432286642406,-48.7422319910997,60.7852865206001,-48.7422319910997,24.5432286642406,-7.09538178661411,0.901742347565181];%num
%inputSample=1:10;
[inputSample, Fs]=audioread('elpasofs16000Nb16_3.wav');% paso del gigante
inputSample=inputSample(1:80000);
Na=length(a);
Nx=length(inputSample);
yy=filter(b,a,inputSample);
u=zeros(1,Na);

for n=1:Nx
    x(1)=inputSample(n);
    tempa=0;
    tempb=0;
    y=0;
    
    for k=2:Na
        tempa=tempa-a(k)*u(k);
        tempb=tempb+b(k)*u(k);
    end
    
    u(1)=x(1)+tempa;
    y=u(1)*b(1)+tempb;
    for m=Na:1-2
        u(m)=u(m-1);
    end
    yy;
    y;
    %pause;
end

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
plot(yy);
xlabel('$Segundos$','Interpreter','latex');
ylabel('$Amplitud$','Interpreter','latex');
title('Señal en el tiempo: el paso del gigante');
grid on;

[Y,W]=freqz(yy,1);
subplot(2,1,2);
plot(W*Fs/(2*pi),abs(Y));
xlabel('$Hz$','Interpreter','latex');
ylabel('$Magnitud$','Interpreter','latex');
title('Señal en frecuencia');
grid on;

%% Muestra depues de filtraje
sound(yy(1:80000), Fs); 
