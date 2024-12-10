function diferente_divizate = Ex2Iterativ(x, y, n)
    diferente_divizate = zeros(n, n);
    diferente_divizate(:, 1) = y;
    for j = 2:n
        for i = 1:n-j+1
            diferente_divizate(i, j) = (diferente_divizate(i+1, j-1) - diferente_divizate(i, j-1)) / (x(i+j-1) - x(i));
        end
    end
    diferente_divizate = diferente_divizate(1, :);
end
