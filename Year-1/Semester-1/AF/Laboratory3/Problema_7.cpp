#include <iostream>

void AlocareMatrice(int**& matrice,const int& n)
{
	matrice = new int* [n];
	for (int linie = 0; linie < n; linie++)
		matrice[linie] = new int[n];
}
template <typename T>
void FormareMatrice(T**& matrice, const int& n)
{
	for (int coloana = 0; coloana < n; coloana++)
		matrice[0][coloana] = coloana + 1;
	for (int linie = 1; linie < n; linie++)
	{
		for (int coloana = n - 1; coloana > 0; coloana--)
			matrice[linie][coloana] = matrice[linie - 1][coloana - 1];
		matrice[linie][0] = matrice[linie][1] + 1;
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
	AlocareMatrice(matrice, n);
	FormareMatrice(matrice, n);
	AfisareMatrice(matrice, n);
	DealocareMatrice(matrice, n);
	return 0;
}