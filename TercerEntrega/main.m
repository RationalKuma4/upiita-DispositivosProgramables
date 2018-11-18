clear all;
close all;
clc;

%% Obtenemos vectores de silabas
[bro,Fs] = audioread('bro.wav');
[fa,Fs] = audioread('fa.wav');
[ma,Fs] = audioread('ma.wav');
[mo,Fs] = audioread('mo.wav');
[pa,Fs] = audioread('pa.wav');
[ro,Fs] = audioread('ro.wav');

%% Normalizamos valores

vectorBro=VectorNormalizado(bro);
vectorFa=VectorNormalizado(fa);
vectorMa=VectorNormalizado(ma);
vectorMo=VectorNormalizado(mo);
vectorPa=VectorNormalizado(pa);
vectorRo=VectorNormalizado(ro);

%% Obtenemos matriz de coeficientes
broMatriz=MatrizMel('bro.wav');
faMatriz=MatrizMel('fa.wav');
maMatriz=MatrizMel('ma.wav');
moMatriz=MatrizMel('mo.wav');
paMatriz=MatrizMel('pa.wav');
roMatriz=MatrizMel('ro.wav');

%% Escribimos coeficientes
dlmwrite('vbro.txt', vectorBro, 'delimiter', ',', 'precision', 5);
dlmwrite('vfa.txt', vectorFa, 'delimiter', ',', 'precision', 5);
dlmwrite('vma.txt', vectorMa, 'delimiter', ',', 'precision', 5);
dlmwrite('vmo.txt', vectorMo, 'delimiter', ',', 'precision', 5);
dlmwrite('vpo.txt', vectorPa, 'delimiter', ',', 'precision', 5);
dlmwrite('vro.txt', vectorRo, 'delimiter', ',', 'precision', 5);

%% Escribimos matrices
dlmwrite('cbro.txt', broMatriz, 'delimiter', ',', 'precision', 5);
dlmwrite('cfa.txt', faMatriz, 'delimiter', ',', 'precision', 5);
dlmwrite('cma.txt', maMatriz, 'delimiter', ',', 'precision', 5);
dlmwrite('cmo.txt', moMatriz, 'delimiter', ',', 'precision', 5);
dlmwrite('cpo.txt', paMatriz, 'delimiter', ',', 'precision', 5);
dlmwrite('cro.txt', roMatriz, 'delimiter', ',', 'precision', 5);
