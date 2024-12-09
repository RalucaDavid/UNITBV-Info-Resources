#include <iostream>
#include <stdlib.h>

void AlocareDinamica(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	matrice = new int* [nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
		matrice[linie] = new int[nrColoane];
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

void CitireMatrice(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	std::cout << "Introduceti elementele matricei" << std::endl;
	for (int linie = 0; linie < nrLinii; linie++)
		for (int coloana = 0; coloana < nrColoane; coloana++)
			std::cin >> matrice[linie][coloana];
	std::cout << "Citirea s-a facut cu succes!" << std::endl;
}

void Interschimbare(int& element1, int& element2)
{
	int auxiliar = element1;
	element1 = element2;
	element2 = auxiliar;
}

void InterschimbareLinii(int**& matrice, int linie, int linie1, int nrColoane)
{
	for (int coloana = 0; coloana < nrColoane; coloana++)
		Interschimbare(matrice[linie][coloana], matrice[linie1][coloana]);
}

int Partitie(int**& matrice, int indexStart, int indexFinal,int nrColoane,int coloana)
{
	int pivot = matrice[indexFinal][coloana];
	int index = indexStart;
	for (int contor = indexStart; contor <= indexFinal; contor++)
	{
		if (matrice[contor][coloana] <= pivot)
		{
			InterschimbareLinii(matrice,contor,index, nrColoane);
			index++;
		}
	}
	return index - 1;
}

int PartitieLinie(int**& matrice, int indexStart, int indexFinal,int linie)
{
	int pivot = matrice[linie][indexFinal];
	int index = indexStart;
	for (int contor = indexStart; contor <= indexFinal; contor++)
	{
		if (matrice[linie][contor] <= pivot)
		{
			Interschimbare(matrice[linie][contor], matrice[linie][index]);
			index++;
		}
	}
	return index - 1;
}

void QuickSortLinie(int**& matrice, int indexStart, int indexFinal,int linie)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = PartitieLinie(matrice, indexStart, indexFinal,linie);
		QuickSortLinie(matrice, indexStart, partitie - 1,linie);
		QuickSortLinie(matrice, partitie + 1, indexFinal,linie);
	}
}

void QuickSortColoana(int**& matrice, int indexStart, int indexFinal, int nrColoane, int coloana)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = Partitie(matrice, indexStart, indexFinal,nrColoane,coloana);
		QuickSortColoana(matrice, indexStart, partitie - 1,nrColoane,coloana);
		QuickSortColoana(matrice, partitie + 1, indexFinal,nrColoane,coloana);
	}
}

void FormareSir(int*& vector, int& dim)
{
	srand(time(NULL));
	for (int index = 0; index < dim; index++)
		vector[index] = rand();
}

int CautareBinara(int**& matrice, int stanga, int dreapta, const int& element)
{
	while (stanga <= dreapta)
	{
		int mijloc = (stanga + dreapta) / 2;
		if (matrice[0][mijloc] == element)
			return 1;
		else if (matrice[0][mijloc] > element)
			dreapta = mijloc - 1;
		else
			stanga = mijloc + 1;
	}
	return 0;
}

int VerifCateNrSir(int**& matrice,int& m)
{
	int dim = 101;
	int* vector = new int[dim];
	FormareSir(vector, dim);
	int nr = 0;
	for (int index = 0; index < dim; index++)
		if (CautareBinara(matrice, 0, m - 1, vector[index]))
			nr++;
	return nr;
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
		std::cout << "Dimensiunile nu sunt valide" << std::endl;
		return 0;
	}
	else
	{
		AlocareDinamica(matrice, n, m);
		CitireMatrice(matrice, n, m);
		QuickSortColoana(matrice, 0,n-1,m,0);
		QuickSortLinie(matrice, 0, m - 1,0);
		std::cout<<"Numarul numerelor din sir care se afla pe prima linie a matricei este de "<<VerifCateNrSir(matrice,m)<<std::endl;
		DealocareDinamica(matrice, n);
	}
	return 0;
}