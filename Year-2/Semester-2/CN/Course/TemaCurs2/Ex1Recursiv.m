function y_interp = Ex1Recursiv(z, x, y)
    y_interp = zeros(size(z));
    for k = 1:length(z)
        y_interp(k) = recursiv(z(k), x, y, 1, length(x));
    end
end

function L = recursiv(z, x, y, i, j)
    if i==j
        L = y(i);
    else
        L = ((z-x(j)) * recursiv(z, x, y, i, j-1) - (z-x(i))*recursiv(z,x,y,i+1,j)) / (x(i)-x(j));
    end
end