#include <iostream>

void EliminareElement(int &n, int tablou[], int &pozitie)
{
	for (int index = pozitie; index < n - 1; index++)
		tablou[index] = tablou[index + 1];
	n--;
	p--;
}
void CitireTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void ElimSiAdaugareP(const int &n,int tablou[], int p)
{
	EliminareElement(n, tablou, p);
	for (int index = n; index > 0; index--)
		tablou[index] = tablou[index - 1];
	tablou[0] = p+1;
}
void AfisareTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cout << tablou[index] << " ";
}
int main()
{
	int n,p;
	std::cout << "Introduceti dimensiunea vectorului si p:";
    std::cin >> n>>p;
	int* tablou = new int[n];
	std::cout << "Introduceti elementele vectorului:";
	CitireTablou(tablou,n);
	ElimSiAdaugareP(n,tablou,p);
	AfisareTablou(tablou,n);
	delete[] tablou;
	return 0;
}