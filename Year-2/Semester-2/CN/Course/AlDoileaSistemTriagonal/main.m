% Sterge fisierele vechi
files = dir('*_*.txt');
if ~isempty(files)
    fclose('all');
    for i = 1:length(files)
        filename = files(i).name;
        delete(filename);
    end
end
GenerareDateIntrare;
Rezolvare;