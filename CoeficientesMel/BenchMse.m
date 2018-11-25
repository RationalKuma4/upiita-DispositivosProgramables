clear all;
close all;
clc;

matrizCivi=MatrizMel("bro.wav");
matrizEntrada=MatrizMel('bro.wav');

mse=MeanSquareError(matrizCivi, matrizEntrada);

