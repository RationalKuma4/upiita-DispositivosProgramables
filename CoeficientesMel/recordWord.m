close all;
clear all;
clc;

recobj=audiorecorder;
disp("palabra");
recordblocking(recobj,1);
hand=getaudiodata(recobj);
audiowrite('robot.wav',hand,8000);