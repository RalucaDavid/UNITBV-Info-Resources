function P = Ex3Iterativ(z, x, y)
    n = length(x) - 1;
    F = Ex2Recursiv(x,y,length(x));
    divided_difference = F(1,:);
    P = y(x == x(1));
    x_product = 1;
    for i = 2:n+1
        x_product = x_product * (z - x(i-1));
        P = P + divided_difference(i) * x_product;
    end
end
