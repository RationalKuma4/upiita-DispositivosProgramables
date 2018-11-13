function [ winSecPreEnf ] = filtroPreEnf( palabra )
    [~, longPal]=size(palabra);
    winSecPreEnf=zeros(1,longPal);
    for i=2:1:longPal
        winSecPreEnf(i)=palabra(i)-0.95*palabra(i-1);
    end
end