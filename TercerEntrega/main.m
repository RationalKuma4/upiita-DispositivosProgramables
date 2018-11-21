clear all;
close all;
clc;

%% Agregamos ruta de archivos
currentFile = mfilename( 'fullpath' );
[pathstr,~,~] = fileparts( currentFile );
addpath( fullfile( pathstr, 'Audios' ) );
    
% Obtenemos vectores de silabas
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
matrizbro=MatrizMel('bro.wav');
matrizfa=MatrizMel('fa.wav');
matrizma=MatrizMel('ma.wav');
matrizmo=MatrizMel('mo.wav');
matrizpa=MatrizMel('pa.wav');
matrizro=MatrizMel('ro.wav');

%% Escribimos coeficientes
dlmwrite('vbro.txt', vectorBro, 'delimiter', ',', 'precision', 5);
dlmwrite('vfa.txt', vectorFa, 'delimiter', ',', 'precision', 5);
dlmwrite('vma.txt', vectorMa, 'delimiter', ',', 'precision', 5);
dlmwrite('vmo.txt', vectorMo, 'delimiter', ',', 'precision', 5);
dlmwrite('vpo.txt', vectorPa, 'delimiter', ',', 'precision', 5);
dlmwrite('vro.txt', vectorRo, 'delimiter', ',', 'precision', 5);

%% Escribimos matrices
dlmwrite('cbro.txt', matrizbro, 'delimiter', ',', 'precision', 5);
dlmwrite('cfa.txt', matrizfa, 'delimiter', ',', 'precision', 5);
dlmwrite('cma.txt', matrizma, 'delimiter', ',', 'precision', 5);
dlmwrite('cmo.txt', matrizmo, 'delimiter', ',', 'precision', 5);
dlmwrite('cpo.txt', matrizpa, 'delimiter', ',', 'precision', 5);
dlmwrite('cro.txt', matrizro, 'delimiter', ',', 'precision', 5);
