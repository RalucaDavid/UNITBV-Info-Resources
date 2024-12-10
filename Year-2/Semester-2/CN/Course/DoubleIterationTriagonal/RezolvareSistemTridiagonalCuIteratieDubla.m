function x = RezolvareSistemTridiagonalCuIteratieDubla(a, b, c, d)
    n = length(a);
    R = zeros(n, 1);
    S = zeros(n, 1);
    x = zeros(n, 1);
    % Primul parcurs
    R(2) = -c(1)/a(1);
    S(2) = d(1)/a(1);
    for i = 2:n-1
        R(i+1)=-c(i)/(a(i)+b(i)*R(i));
        S(i+1)=(d(i)-b(i)*S(i))/(a(i)+b(i)*R(i));
    end
    % Al doilea parcurs
    x(n) = (d(n)-b(n)*S(n))/(a(n)+b(n)*R(n));
    for i = n-1:-1:1
        x(i)=R(i+1)*x(i+1)+S(i+1);
    end
end
