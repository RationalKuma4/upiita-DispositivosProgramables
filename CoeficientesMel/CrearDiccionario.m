function [] = CrearDiccionario(tamanoDiccionario)
    recObj = audiorecorder;
    
    for index=1:tamanoDiccionario
        disp('Habla (1.5s)')
        recordblocking(recObj, 1.5);
        disp('Final de grabacion.');
        y = getaudiodata(recObj);
        nombre=strcat(int2str(index), '.wav');
        audiowrite(nombre,y,8000);
        disp('');
    end
end

