function y_interp = Ex2Recursiv(x, y, n)
    y_interp = zeros(1, n);
    for k = 1:n
        y_interp(k) = recursiv(x, y, 1, k);
    end
end

function f = recursiv(x, y, i, j)
    if i == j
        f = y(i);
    else
        f = (recursiv(x, y, i, j-1) - recursiv(x, y, i+1, j)) / (x(i) - x(j));
    end
end
