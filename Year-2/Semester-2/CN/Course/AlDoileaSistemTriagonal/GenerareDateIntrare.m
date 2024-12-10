sizes = [10^3, 10^4, 10^5, 10^6];
for i = 1:length(sizes)
    n = sizes(i);
    a = rand(n, 1);
    writematrix(a, ['a_' num2str(n) '.txt']);
    b = rand(n, 1);
    writematrix(b, ['b_' num2str(n) '.txt']);
    c = rand(n, 1);
    writematrix(c, ['c_' num2str(n) '.txt']);
    d = rand(n, 1);
    writematrix(d, ['d_' num2str(n) '.txt']);
end
