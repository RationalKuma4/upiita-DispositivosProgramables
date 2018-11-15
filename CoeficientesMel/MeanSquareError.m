function [mse] = MeanSquareError(referencia,aproximacion)
    D = abs(referencia-aproximacion).^2;
    mse = sum(D(:))/numel(referencia);
end

