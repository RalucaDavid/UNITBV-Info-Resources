#include <iostream>

void AlocareDinamica(int**& matrice, const int& dimensiune)
{
	matrice = new int* [dimensiune];
	for (int linie = 0; linie < dimensiune; linie++)
		matrice[linie] = new int[dimensiune];
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

void CitireMatrice(int**& matrice, const int& dimensiune)
{
	std::cout << "Introduceti elementele matricei" << std::endl;
	for (int linie = 0; linie < dimensiune; linie++)
		for (int coloana = 0; coloana < dimensiune; coloana++)
			std::cin >> matrice[linie][coloana];
	std::cout << "Citirea s-a facut cu succes!" << std::endl;
}

void AfisareMatrice(int**& matrice, const int& dimensiune)
{
	for (int linie = 0; linie < dimensiune; linie++)
	{
		for (int coloana = 0; coloana < dimensiune; coloana++)
			std::cout << matrice[linie][coloana] << ' ';
		std::cout << std::endl;
	}
}

void DealocareDinamica(int**& matrice, const int& dimensiune)
{
	for (int linie = 0; linie < dimensiune; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!"<<std::endl;
}
int main()
{
	int n, m;
	int** matrice = {};
	std::cout << "Introduceti dimensiunile matricei:";
	std::cin >> n;
	if (n < 0)
	{
		std::cout << "Dimensiunea nu este valida" << std::endl;
		return 0;
	}
	AlocareDinamica(matrice, n);
	CitireMatrice(matrice, n);
	AfisareMatrice(matrice, n);
	DealocareDinamica(matrice, n);
	return 0;
}