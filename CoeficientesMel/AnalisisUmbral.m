function [ evolucionUmbral ] = AnalisisUmbral( Y )
    [~, columnas]=size(Y);
    i=floor(columnas/1024);%numero de veces que calculara el umbral (nºtramas, se usara para el bucle exterior)
    m=2; %factor de índice de inicio, empieza por 2 porque necesitaremos
    dato(x-1)
    n=1026;% factor de índice final
    evolucionUmbral=zeros(1, columnas);

    for j=1:1:i
        umbral=0;
        for k=m:1:n
            umbral=umbral+abs(Y(k)*abs(Y(k))-Y(k-1)*abs(Y(k-1)));
        end
        evolucionUmbral(n)=umbral; %se almacena el valor cada 1024 muestraspara luego poder comparar con la señal de entrada
        m=m+1024;
        n=n+1024;
    end
end
