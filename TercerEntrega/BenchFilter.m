clear all;
close all;
clc;

[yy,Fs]=audioread('bro.wav');
yy=yy';
yy=yy/max(yy);
m=MatrizMel('bro.wav');
%%[palabradelimitada]=detectorExtremos(yy);
%%[palabradelimitada, longPal]=detectorExtremos(yy);
%%y1=palabradelimitada;

%%


%%y=FilterFoo(yy)
