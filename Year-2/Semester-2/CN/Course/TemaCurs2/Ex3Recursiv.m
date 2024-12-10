function P = Ex3Recursiv(z, x, y)
    n = length(x);
    F = Ex2Recursiv(x, y, n);
    divided_difference = F(1,:);
    P = computePolynomial(z, x, divided_difference, 1, n); 
end

function P = computePolynomial(z, x, divided_difference, k, n)
        if k > n
            P = 0;
        else
            i=1;
            x_product = 1;
            while i < k
                x_product = x_product * (z - x(i));
                i=i+1;
            end
            P = divided_difference(k) * x_product + computePolynomial(z, x, divided_difference, k+1, n);
        end
end
