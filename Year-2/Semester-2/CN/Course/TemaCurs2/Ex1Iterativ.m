function y_interp = Ex1Iterativ(z, x, y)
    y_interp = zeros(size(z));
    n = length(x);
    
    for k = 1:length(z)
        zk = z(k);
        L = zeros(n, n);
        
        for i = 1:n
            L(i, i) = y(i);
        end
        
        for len = 2:n
            for i = 1:n-len+1
                j = i + len - 1;
                L(i, j) = ((zk - x(j)) * L(i, j-1) - (zk - x(i)) * L(i+1, j)) / (x(i) - x(j));
            end
        end
        
        y_interp(k) = L(1, n);
    end
end
