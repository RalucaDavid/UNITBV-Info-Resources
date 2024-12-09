#include <iostream>

void AlocareMatrice(int**& matrice, const int& n)
{
	matrice = new int*[n];
	for (int linie = 0; linie < n; linie++)
		matrice[linie] = new int[n];
}
template <typename T>
void CitireMatrice(T**& matrice, const int& n)
{
	std::cout << "Introduceti elementele matricei:"<<std::endl;
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < n; coloana++)
			std::cin >> matrice[linie][coloana];
}
template <typename T>
int MaxDiagPrincipala(T**& matrice, const int& n)
{
	int maxim = matrice[0][0];
	int pozitie = 0;
	for (int index = 1; index < n; index++)
		if (maxim < matrice[index][index])
		{
			maxim = matrice[index][index];
			pozitie = index;
		}
	return pozitie;
}
template <typename T>
int MinDiagSecundara(T**& matrice, const int& n)
{
	int minim = matrice[0][n - 1];
	int pozitie = 0;
	for (int index = 1; index < n; index++)
		if (minim > matrice[index][n - 1 - index])
		{
			minim = matrice[index][n - 1 - index];
			pozitie = index;
		}
	return pozitie;
}
void Interschimbare(int& nr1, int& nr2)
{
	int aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}
template <typename T>
void InterMaxDPMinDS(T**& matrice, const int& n)
{
	int pozMax = MaxDiagPrincipala(matrice, n);
	int pozMin = MinDiagSecundara(matrice, n);
	Interschimbare(matrice[pozMax][pozMax], matrice[pozMin][n - 1 - pozMin]);
}
template <typename T>
void AfisareMatrice(T**& matrice, const int& n)
{
	std::cout <<std:: endl;
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
int main()
{
	int n;
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	if(n<0)
		return 0;
	int** matrice = {};
	AlocareMatrice(matrice, n);
	CitireMatrice(matrice, n);
	InterMaxDPMinDS(matrice, n);
	AfisareMatrice(matrice, n);
	DealocareMatrice(matrice, n);
	return 0;
}