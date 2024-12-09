#include <iostream>
#include <fstream>

void AlocareDinamica(int**& matrice, int& dimensiune)
{
	matrice = new int* [dimensiune];
	for (int linie = 0; linie < dimensiune; linie++)
	{
		matrice[linie] = new int[dimensiune];
	}
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

bool CitireMatrice(int**& matrice, int& dimensiune)
{
	std::ifstream Fin("FisierIntrare.in");
	if (!Fin.is_open())
	{
		std::cout << "Fisierul nu exista sau nu a putut fi deschis!" << std::endl;
		return false;
	}
	Fin >> dimensiune;
	if (dimensiune < 0)
	{
		std::cout << "Dimensiunea este invalid!" << std::endl;
		return false;
	}
	AlocareDinamica(matrice, dimensiune);
	for (int linie = 0; linie < dimensiune; linie++)
		for (int coloana = 0; coloana < dimensiune; coloana++)
		{
			if (Fin.eof())
			{
				std::cout << "Fisierul nu are destule elemente!"<<std::endl;
				return false;
			}
			Fin >> matrice[linie][coloana];
		}
	std::cout << "Citirea s-a facut cu succes!" << std::endl;
	Fin.close();
	return true;
}

void AfisareMatrice(int**& matrice, int& dimensiune)
{
	std::ofstream Fout("FisierIesire.out");
	for (int linie = 0; linie < dimensiune; linie++)
	{
		for (int coloana = 0; coloana < dimensiune; coloana++)
			Fout << matrice[linie][coloana] << ' ';
		Fout << std::endl;
	}
	Fout.close();
}

void DealocareDinamica(int**& matrice, int& dimensiune)
{
	for (int linie = 0; linie < dimensiune; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!" << std::endl;
}

int main()
{
	int n = 0;
	int** matrice = {};
	if (CitireMatrice(matrice, n))
	{
		AfisareMatrice(matrice, n);
		DealocareDinamica(matrice, n);
	}
	return 0;
}