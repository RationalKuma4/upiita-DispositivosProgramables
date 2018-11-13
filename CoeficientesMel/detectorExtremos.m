function [ palabradelimitada , longPal ] = detectorExtremos( Y )
    [~, columnas]=size(Y);
    i=floor(columnas/1024);%numero de veces que calculara el umbral(nºtramas)
    m=2; %factor de índice de inicio, empieza por 2 porque necesitaremos
    dato(x-1)
    n=1026;% factor de índice final
    %esto contara las ventanas consecutivas sin info. para detectar final pronunciación.
    longPal=1;
    t=0;

    for j=1:1:i %esto segmentara la señal en tramas
        umbral=0;
        for k=m:1:n %bucle recorre muestras de n a m y calcula el umbral de la trama
            umbral=umbral+abs(Y(k)*abs(Y(k))-Y(k-1)*abs(Y(k-1)));
        end

        %evolucionUmbral(n)=umbral; %se almacena el valor cada 1024 posiciones
        %=DETECTOR INICIO=> si supera umbral se empieza a almacenar tramas
        if (umbral>1.25) %comprobamos si se detecta inicio, si supera Umbral Inicio=1.25
            t=0;
            longPal=longPal+1024;
            palabradelimitada(longPal-1024:longPal)=Y(m:n); %almacenamos tramas si t<15
        end
        %=DETECTOR FIN=> se detecta final si transcurren 15 tramas sin info (t=15)
        if (umbral<1) %comprobamos si incrementamos t,
            if (t<10 && longPal~=1)
                t=t+1;
                longPal=longPal+1024;
                palabradelimitada(longPal-1024:longPal)=Y(m:n);
                %almacenamos tramas si t<15
            end
        end
        m=m+1024;
        n=n+1024;
    end
end