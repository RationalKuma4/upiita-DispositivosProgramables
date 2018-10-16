close all;
clear all;
clc;

recobj=audiorecorder;
recordblocking(recobj,1);
hand=getaudiodata(recobj);
audiowrite('pollo.wav',hand,8000);