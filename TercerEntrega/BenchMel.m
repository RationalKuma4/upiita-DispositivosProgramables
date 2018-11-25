clear all;
close all;
clc;

y=dlmread('y.txt');
Hm=dlmread('Hm.txt');
W=dlmread('W.txt');

mfcc=MatrizFreMel(y,Hm,W);

