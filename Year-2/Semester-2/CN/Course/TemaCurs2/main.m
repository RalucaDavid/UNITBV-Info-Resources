%Capitolul 10, Subcapitolul I, Problema 5

%Datele problemei
f = @(x)sin(x);
x = -pi/2 + (0:10)*pi/10;
y = f(x);
z = pi/13;

%Rezolvare după culegere
verificare = PolinomInterpolareLagrangeBaricentrica(z,x,y);

%Teorema 2.4.2
ex1Recursiv = Ex1Recursiv(z,x,y);
ex1Iterativ = Ex1Iterativ(z,x,y);

%Teorema 2.4.4
ex2Recursiv = Ex2Recursiv(x, y, length(x));
ex2Iterativ = Ex2Iterativ(x,y, length(x));

%Teorema 2.4.7
ex3Recursiv = Ex3Recursiv(z, x, y);
ex3Iterativ = Ex3Iterativ(z, x, y);

%Salvare în fisier
fid = fopen('rezultate.txt', 'w');
fprintf(fid, 'Rezultate pentru problema Capitolul 10, Subcapitolul I, Problema 5:\n');
fprintf(fid, 'Verificare PolinomInterpolareLagrangeBaricentrica: %f\n', verificare);
fprintf(fid, 'Rezultate pentru Teorema 2.4.2:\n');
fprintf(fid, 'Ex1Recursiv: %f\n', ex1Recursiv);
fprintf(fid, 'Ex1Iterativ: %f\n', ex1Iterativ);
fprintf(fid, 'Rezultate pentru Teorema 2.4.4:\n');
fprintf(fid, 'Ex2Recursiv: %f\n', ex2Recursiv);
fprintf(fid, 'Ex2Iterativ: %f\n', ex2Iterativ);
fprintf(fid, 'Rezultate pentru Teorema 2.4.7:\n');
fprintf(fid, 'Ex3Recursiv: %f\n', ex3Recursiv);
fprintf(fid, 'Ex3Iterativ: %f\n', ex3Iterativ);
fclose(fid);