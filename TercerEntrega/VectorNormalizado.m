function [vector] = VectorNormalizado(y)
    yy=y';
    yy=yy/max(yy);
    [vector,longPal]=detectorExtremos(yy);
  
    [r,c]=size(vector);
    diferenciaCol=3080-c;
    b=padarray(vector,[0 diferenciaCol],0,'post');
    b(isnan(b))=0;
    vector=b;
end

