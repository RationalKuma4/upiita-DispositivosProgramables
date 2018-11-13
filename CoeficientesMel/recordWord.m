close all;
clear all;
clc;

recobj=audiorecorder;
recordblocking(recobj,1);
hand=getaudiodata(recobj);
audiowrite('civilizacion.wav',hand,8000);