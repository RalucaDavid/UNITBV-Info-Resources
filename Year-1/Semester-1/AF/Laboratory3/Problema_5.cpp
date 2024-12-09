#include <iostream>

void AlocareMatrice(int**& matrice, const int& n)
{
	matrice = new int* [n];
	for (int linie = 0; linie < n; linie++)
		matrice[linie] = new int[n];
}
template <typename T>
void CitireMatrice(T**& matrice, const int& n)
{
	std::cout << "Introduceti elementele matricei:" << std::endl;
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < n; coloana++)
			std::cin >> matrice[linie][coloana];
	std::cout << std::endl;
}
template <typename T>
void AfisareMatrice(T**& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
	{
		for (int coloana = 0; coloana < n; coloana++)
			std::cout << matrice[linie][coloana] << ' ';
		std::cout << std::endl;
	}
}
void DealocareMatrice(int**& matrice, int& n)
{
	for (int linie = 0; linie < n; linie++)
		delete[] matrice[linie];
	delete[] matrice;
}
template<typename T>
void Rotire90(T * *&matrice, int& n)
{
    int** matrice1 = {};
    AlocareMatrice(matrice1, n);
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < n; coloana++)
			matrice1[linie][coloana]=matrice[n-1-coloana][linie];
    AfisareMatrice(matrice1, n);
    DealocareMatrice(matrice1, n);
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
	CitireMatrice(matrice, n);
	Rotire90(matrice, n);
	DealocareMatrice(matrice, n);
	return 0;
}