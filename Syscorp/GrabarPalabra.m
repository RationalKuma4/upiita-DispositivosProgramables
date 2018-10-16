function [nombreArchivo] = GrabarPalabra(nombre)
%GrabarArchivo 
%   Graba una palabra de 1 segundo
    recobj=audiorecorder;
    recordblocking(recobj,1);
    hand=getaudiodata(recobj);
    audiowrite(nombre+'.wav',hand,8000);
    nombreArchivo=nombre;
end

