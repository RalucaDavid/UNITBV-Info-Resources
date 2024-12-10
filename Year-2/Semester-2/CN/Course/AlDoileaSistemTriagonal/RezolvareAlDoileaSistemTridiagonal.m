function x = RezolvareAlDoileaSistemTridiagonal(a, b, c, d)
    n = length(a);
    R = zeros(n, 1);
    S = zeros(n, 1);
    W = zeros(n, 1);
    x = zeros(n, 1);
    R(2) = -c(1)/a(1);
    S(2) =  d(1)/a(1);
    W(2) = -b(1)/a(1);
    for i=1:n-1
        R(i+1) = -c(i) / (a(i) + b(i)*R(i));
        S(i+1) = (d(i)-b(i)*S(i)) / (a(i)+b(i)*R(i));
        W(i+1) = -b(i)*W(i)/(a(i)+b(i)*R(i));
    end
    U = zeros(n, 1);
    V = zeros(n, 1);
    U(n) = 1;
    V(n) = 0;
    for i=n:-1:2
        U(i-1) = R(i)*U(i) + W(i);
        V(i-1) = R(i)*V(i) + S(i);
    end
    x(n) = (d(n)-b(n)*V(n-1)-c(n)*V(1)) / (a(n)+b(n)*U(n-1)+c(n)*U(1));
    for i=n-1:-1:1
        x(i) = U(i)*x(n)+V(i);
    end
end
