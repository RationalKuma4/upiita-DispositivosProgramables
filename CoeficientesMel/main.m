clear all;
close all;
clc;

%% Diccionario y coeficientes
nombreArchivos=["civilizacion.wav", "cosmonauta.wav", "filtro.wav",...
    "gato.wav", "laser.wav", "libro.wav", "perico.wav", "perro.wav",...
    "proton.wav", "robot.wav"];

% Agregamos ruta de archivos
currentFile = mfilename( 'fullpath' );
[pathstr,~,~] = fileparts( currentFile );
addpath( fullfile( pathstr, 'Audios' ) );

% Obetenmos coeficientes de nuestro diccionario
matrizCivi=MatrizMel(nombreArchivos(1));
matrizCosmo=MatrizMel(nombreArchivos(2));
matrizFiltro=MatrizMel(nombreArchivos(3));
matrizGato=MatrizMel(nombreArchivos(4));
matrizLaser=MatrizMel(nombreArchivos(5));
matrizLibro=MatrizMel(nombreArchivos(6));
matrizPerico=MatrizMel(nombreArchivos(7));
matrizPerro=MatrizMel(nombreArchivos(8));
matrizProton=MatrizMel(nombreArchivos(9));
matrizRobot=MatrizMel(nombreArchivos(10));

mtricesMel=[matrizCivi, matrizCosmo, matrizFiltro, matrizGato, matrizLaser...
    matrizLaser, matrizLibro, matrizPerico, matrizPerro, matrizProton, matrizRobot];

%% Introducimos palabra y escribimos archivo
recObj = audiorecorder;
disp('Habla.')
recordblocking(recObj, 1.2);
disp('Fin de grabacion.');
y = getaudiodata(recObj);
audiowrite('input.wav',y,8000)
% plot(y);


%% Obtenemos coeficientes de la entrada
matrizEntrada=MatrizMel('input.wav');




% Correlacion de las matrices
% output=corr(matrizFiltro, matrizEntrada);
% output(isnan(output))=0;
