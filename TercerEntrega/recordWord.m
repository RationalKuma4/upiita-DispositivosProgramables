close all;
clear all;
clc;

%%
% recobj=audiorecorder;
% disp("palabra");
% recordblocking(recobj,1);
% hand=getaudiodata(recobj);
% audiowrite('robot.wav',hand,8000);

%%

recObj = audiorecorder;
disp('Start speaking.')
recordblocking(recObj, 1.5);
disp('End of Recording.');
play(recObj);
y = getaudiodata(recObj);
plot(y);

%%
X = randn(256,256);
Xapp = randn(256,256);
D = abs(X-Xapp).^2;
MSE = sum(D(:))/numel(X);

%%
close all;
clear all;
clc;
CrearDiccionario(6);