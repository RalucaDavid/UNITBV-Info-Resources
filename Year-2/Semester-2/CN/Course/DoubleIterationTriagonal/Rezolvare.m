function Rezolvare
    sizes = [10^3, 10^4, 10^5, 10^6];
    for i = 1:length(sizes)
        n = sizes(i);
        fisierRezultat = fopen(['rezultat_' num2str(n) '.txt'], 'w');
        a = readmatrix(['a_' num2str(n) '.txt']);
        b = readmatrix(['b_' num2str(n) '.txt']);
        c = readmatrix(['c_' num2str(n) '.txt']);
        d = readmatrix(['d_' num2str(n) '.txt']);
        x = RezolvareSistemTridiagonalCuIteratieDubla(a, b, c, d);
        fprintf(fisierRezultat, '%f\n', x);
        fclose(fisierRezultat);
    end
end
