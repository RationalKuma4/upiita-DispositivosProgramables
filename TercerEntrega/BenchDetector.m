[yy,Fs]=audioread('bro.wav');
yy=yy';
yy=yy/max(yy);
palabraRecortada=detectorExtremos(yy);