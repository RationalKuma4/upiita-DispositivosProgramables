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

palabra1=Palabra;
palabra1.PalabraContenido = nombreArchivos(1);
palabra1.MatrizMel = matrizCivi;

palabra2=Palabra;
palabra2PalabraContenido = nombreArchivos(2);
palabra2.MatrizMel = matrizCosmo;

palabra3=Palabra;
palabra3.PalabraContenido = nombreArchivos(3);
palabra3.MatrizMel = matrizFiltro;

palabra4=Palabra;
palabra4.PalabraContenido = nombreArchivos(4);
palabra4.MatrizMel = matrizGato;

palabra5=Palabra;
palabra5.PalabraContenido = nombreArchivos(5);
palabra5.MatrizMel = matrizLaser;

palabra6=Palabra;
palabra6.PalabraContenido = nombreArchivos(6);
palabra6.MatrizMel = matrizLibro;

palabra7=Palabra;
palabra7.PalabraContenido = nombreArchivos(7);
palabra7.MatrizMel = matrizPerico;

palabra8=Palabra;
palabra8.PalabraContenido = nombreArchivos(8);
palabra8.MatrizMel = matrizPerro;

palabra9=Palabra;
palabra9.PalabraContenido = nombreArchivos(9);
palabra9.MatrizMel = matrizProton;

palabra10=Palabra;
palabra10.PalabraContenido = nombreArchivos(10);
palabra10.MatrizMel = matrizRobot;

palabras=[palabra1,palabra2,palabra3,palabra4,palabra5,palabra6,palabra7...
    ,palabra8,palabra9,palabra10];

%% Introducimos palabra y escribimos archivo
recObj = audiorecorder;
disp('Habla.')
recordblocking(recObj, 1.2);
disp('Fin de grabacion.');
y = getaudiodata(recObj);
audiowrite('input.wav',y,8000)

%% Obtenemos coeficientes de la entrada
matrizEntrada=MatrizMel('input.wav');

listaErrores=[];
listaCorr=[];
for index=1:length(palabras)
    %disp(palabras(index).PalabraContenido);
    
    D=abs(palabras(index).MatrizMel-matrizEntrada).^2;
    MSE=sum(D(:))/numel(palabras(index).MatrizMel);
    error=MSE;
    
    %error=immse(palabras(index).MatrizMel, matrizEntrada);
    palabras(index).Error=error;
    listaErrores(index)=error;
    
    %corr=corr(palabras(index).MatrizMel, matrizEntrada);
    %palabras(index).Correlacion=corr;
    %listaCorr(index)=corr;
end

errorMinimo=min(listaErrores);
corrMax=max(listaCorr);

for index=1:length(palabras)
    %disp(palabras(index).PalabraContenido);
    if(errorMinimo==palabras(index).Error)
        disp('Palabra');
        disp(palabras(index).PalabraContenido);
    end
    
    if(corrMax==palabras(index).Correlacion)
        disp('Palabra correlacion');
        disp(palabras(index).PalabraContenido);
    end
end

% Correlacion de las matrices
% output=corr(matrizFiltro, matrizEntrada);
% output(isnan(output))=0;
