function [vector] = VectorNormalizado(y)
    currentFile = mfilename( 'fullpath' );
    [pathstr,~,~] = fileparts( currentFile );
    addpath( fullfile( pathstr, 'Audios' ) );

    yy=y';
    yy=yy/max(yy);
    %[vector]=detectorExtremos(yy);
  
    %[r,c]=size(yy);
    %diferenciaCol=4000-c;
    %b=padarray(yy,[0 diferenciaCol],0,'post');
    yy(isnan(yy))=0;
    vector=yy;
end

