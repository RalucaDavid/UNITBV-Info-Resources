#include <iostream>

void AlocareMatrice(int**& matrice, int& n, int& m)
{
	matrice = new int* [n];
	for (int linie = 0; linie < n; linie++)
		matrice[linie] = new int[m];
	std::cout << "Alocarea s-a facut cu succes!"<<std::endl;
}
template <typename T>
void CitireMatrice(T**& matrice, const int& n, const int& m)
{
	std::cout << "Introduceti elementele matricei:" << std::endl;
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < m; coloana++)
			std::cin >> matrice[linie][coloana];
}
template <typename T>
int Maxim(T**& matrice, const int& linie, const int& m)
{
	int maxim=matrice[linie][0];
	for (int coloana = 1; coloana < m; coloana++)
		if (maxim < matrice[linie][coloana])
			maxim = matrice[linie][coloana];
	return maxim;
}
template <typename T>
int TotalNrDistincte(T**& matrice,const int& linie,const int& m)
{
	int dimensiune = Maxim(matrice, linie, m)+1;
	int* vectorFrecventa = new int[dimensiune];
	for (int index = 0; index < dimensiune; index++)
		vectorFrecventa[index] = 0;
	for (int coloana = 0; coloana < m; coloana++)
	{
		vectorFrecventa[int(matrice[linie][coloana])]++;
	}
	int NrDistincte = 0;
	for (int index = 0; index < dimensiune; index++)
		if (vectorFrecventa != 0)
			NrDistincte++;
	return NrDistincte;
	delete[] vectorFrecventa;
}
template <typename T>
int NrMaxElDistincte(T**& matrice,int& n, int& m)
{
	int maxim=TotalNrDistincte(matrice,0,m);
	for (int linie = 1; linie < n; linie++)
		if (TotalNrDistincte(matrice, linie, m) > maxim)
			maxim = TotalNrDistincte(matrice, linie, m);
	return maxim;
}
template <typename T>
void AfisareLiniiMaxDistincte(T**& matrice, const int& n, const int& m,const int&maxim)
{
	for (int linie = 0; linie < n; linie++)
	{
		if (maxim == TotalNrDistincte(matrice,n,m))
		{
			for (int coloana = 0; coloana < m; coloana++)
				std::cout << matrice[linie][coloana] << ' ';
			std::cout << std::endl;
		}
	}
}
void DealocareMatrice(int**& matrice, int& n, int& m)
{
	for (int linie = 0; linie < n; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!";
}
int main()
{
	int n, m,maxim;
	std::cout << "Introducere dimensiunile matricei:";
	std::cin >> n >> m;
	if ((n < 0) || (m < 0))
		return 0;
	int** matrice = {};
	AlocareMatrice(matrice, n, m);
	CitireMatrice(matrice, n, m);
	maxim=NrMaxElDistincte(matrice, n, m);
	AfisareLiniiMaxDistincte(matrice, n, m, maxim);
	DealocareMatrice(matrice, n, m);
	return 0;
}