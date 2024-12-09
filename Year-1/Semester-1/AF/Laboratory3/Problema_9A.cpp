#include <iostream>
#include <math.h>

void AlocareMatrice(int**& matrice, const int& n)
{
	matrice = new int* [n];
	for (int linie = 0; linie < n; linie++)
		matrice[linie] = new int[n];
}
void CitireSpiralaMatrice(int**& matrice, int n)
{
	int linie = 0, coloana = 0, index,dimensiune=n;
	while (linie<=(dimensiune+1)/2)
	{
		for (index = linie; index <= n - 1; index++)
			std::cin >> matrice[index][coloana];
		for (index = coloana+1; index < n - 1; index++)
			std::cin >> matrice[n-1][index];
		for (index = n - 1; index > linie; index--)
			std::cin >> matrice[index][n - 1];
		for (index = n - 1; index > coloana; index--)
			std::cin >> matrice[linie][index];
		linie++;
		coloana++;
	    n--;
	}
}
void AfisareMatrice(int**& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
	{
		for (int coloana = 0; coloana < n; coloana++)
			std::cout << matrice[linie][coloana] << ' ';
		std::cout << std::endl;
	}
}
void DealocareMatrice(int**& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
		delete[] matrice[linie];
	delete[] matrice;
}
int main()
{
	int n;
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	if (n < 0)
		return 0;
	int** matrice = {};
	AlocareMatrice(matrice, int(std::sqrt(n)));
	CitireSpiralaMatrice(matrice, int(std::sqrt(n)));
	AfisareMatrice(matrice, int(std::sqrt(n)));
	DealocareMatrice(matrice, int(std::sqrt(n)));
	return 0;
}