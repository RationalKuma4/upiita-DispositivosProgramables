clear all;
close all;
clc;

%% Diccionario y coeficientes
nombreArchivos=["civilizacion.wav", "cosmonauta.wav", "filtro.wav",...
    "gato.wav", "laser.wav", "libro.wav", "perico.wav", "perro.wav",...
    "proton.wav", "robot.wav"];

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
palabra2.PalabraContenido = nombreArchivos(2);
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
recordblocking(recObj, 1.5);
disp('Fin de grabacion.');
y = getaudiodata(recObj);
audiowrite('input.wav',y,8000)

%% Obtenemos coeficientes de la entrada y declaramos listas

matrizEntrada=MatrizMel('input.wav');


%% Operaciones
listaErrores=[];
listaDistanciaEuclidiana=[];
listaCorrelacion=[];

for index=1:length(palabras)
    % Mse
    mse=MeanSquareError(palabras(index).MatrizMel, matrizEntrada);
    palabras(index).Mse=mse;
    listaErrores(index)=mse;
    
    % Distancia euclidiana
    distancia=pdist2(palabras(index).MatrizMel, matrizEntrada);
    sumaDistancia=sum(distancia(:));
    palabras(index).DistanciaEuclidiana=sumaDistancia;
    listaDistanciaEuclidiana(index)=sumaDistancia;
    
    % Correlacion
    correlacion=corr2(palabras(index).MatrizMel, matrizEntrada);
    palabras(index).Correlacion=correlacion;
    listaCorrelacion(index)=correlacion;
end

% Econtrar valores optimos y compara
errorMin=min(listaErrores);
corrMax=max(listaCorrelacion);
distMin=min(listaDistanciaEuclidiana);

for index=1:length(palabras)
    % Mse
    if(errorMin==palabras(index).Mse)
        err=palabras(index).PalabraContenido;
    end
    
    % Distancia
    if(distMin==palabras(index).DistanciaEuclidiana)
        dist=palabras(index).PalabraContenido;
    end
    
    % Correlacion 
    if(corrMax==palabras(index).Correlacion)
        corrr=palabras(index).PalabraContenido;
    end
end

% Reslutados
disp('¿Es alguna de estas palabras?');
disp('Palabra por mse');
disp(err);
disp('Palabra por distancia');
disp(dist);
disp('Palabra por correlacion');
disp(corrr);
% resp=input('s/n ');
% if(resp=='s')
%     disp(':)');
% else
%     disp(':(');
% end
disp('');

