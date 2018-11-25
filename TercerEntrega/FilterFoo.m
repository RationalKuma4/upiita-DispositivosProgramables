function [y] = FilterFoo(y1)
    y=filter([1,-0.95],1,y1);
end

