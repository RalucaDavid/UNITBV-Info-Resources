#include <iostream>

void AlocareDinamica(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	matrice = new int* [nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
		matrice[linie] = new int[nrColoane];
	std::cout << "Alocarea s-a facut cu succes!"<<std::endl;
}

void CitireMatrice(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	std::cout << "Introduceti elementele matricei"<<std::endl;
	for (int linie = 0; linie < nrLinii; linie++)
		for (int coloana = 0; coloana < nrColoane; coloana++)
			std::cin >> matrice[linie][coloana];
	std::cout << "Citirea s-a facut cu succes!"<<std::endl;
}

void AfisareMatrice(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane; coloana++)
			std::cout<< matrice[linie][coloana]<<' ';
		std::cout << std::endl;
	}
}

void DealocareDinamica(int**& matrice, const int& nrLinii)
{
	for (int linie = 0; linie < nrLinii; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!" << std::endl;
}
int main()
{
	int n, m;
	int** matrice = {};
	std::cout << "Introduceti dimensiunile matricei:";
	std::cin >> n >> m;
	if ((n < 0) || (m < 0))
	{
		std::cout << "Dimensiunile nu sunt valide"<<std::endl;
		return 0;
	}
	AlocareDinamica(matrice, n, m);
	CitireMatrice(matrice, n, m);
	AfisareMatrice(matrice, n, m);
	DealocareDinamica(matrice, n);
	return 0;
}