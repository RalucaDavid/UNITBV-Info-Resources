#include <iostream>
#include <fstream>

void AlocareDinamica(int**& matrice,int&nrLinii,int&nrColoane)
{
	matrice = new int*[nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
	{
		matrice[linie] = new int[nrColoane];
	}
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

bool CitireMatrice(int**& matrice, int& nrLinii, int& nrColoane)
{
	std::ifstream fin("FisierIntrare.in");
	if (!fin.is_open())
	{
		std::cout << "Fisierul nu exista sau nu a putut fi deschis!" << std::endl;
		return false;
	}
	fin >> nrLinii >> nrColoane;
	if ((nrLinii < 0) || (nrColoane < 0))
	{
		std::cout << "Unul dintre parametri este invalid!"<<std::endl;
		return false;
	}
	AlocareDinamica(matrice, nrLinii, nrColoane);
	for (int linie = 0; linie < nrLinii; linie++)
		for (int coloana = 0; coloana < nrColoane; coloana++)
		{
			if (fin.eof())
			{
				std::cout << "Am ajuns la finalul fisierului";
				return false;
			}
			fin >> matrice[linie][coloana];
		}
	std::cout << "Citirea s-a facut cu succes!"<<std::endl;
	fin.close();
	return true;
}

void AfisareMatrice(int**& matrice, int& nrLinii, int& nrColoane)
{
	std::ofstream fout("FisierIesire.out");
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane; coloana++)
			fout << matrice[linie][coloana] << ' ';
		fout << std::endl;
	}
	fout.close();
}

void DealocareDinamica(int**& matrice, int& nrLinii)
{
	for (int linie = 0; linie < nrLinii; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!" << std::endl;
}

int main()
{
	int n=0, m=0;
	int** matrice = {};
	if(CitireMatrice(matrice, n, m))
	{
		AfisareMatrice(matrice, n, m);
		DealocareDinamica(matrice, n);
	}
	return 0;
}