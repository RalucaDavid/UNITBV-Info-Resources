#include <iostream>
#include <fstream>

// Credit: David Raluca 

bool Validare(int n, int m)
{
	if ((n < 4) || (n > 100))
		return false;
	else if ((m < 4) || (m >= 100))
		return false;
	return true;
}
void AlocareDinamica(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	matrice = new int* [nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
		matrice[linie] = new int[nrColoane];
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

void CitireMatrice(int**& matrice,int& nrLinii,int& nrColoane)
{
	int k;
	std::ifstream FisierIntrare("Fisier.in");
	FisierIntrare >> nrLinii >> nrColoane>>k;
	for (int linie = 0; linie < nrLinii; linie++)
		for (int coloana = 0; coloana < nrColoane; coloana++)
			FisierIntrare>> matrice[linie][coloana];
	std::cout << "Citirea s-a facut cu succes!" << std::endl;
	FisierIntrare.close();
}

int CeaMaiIntalnitaCuloare(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	int* vectorFrecventa = new int[nrColoane];
	for (int index = 0; index < nrColoane; index++)
		vectorFrecventa[index] = 0;
	for (int coloana = 0; coloana < nrColoane; coloana++)
	{
		for (int linie = 0; linie < nrLinii; linie++)
			vectorFrecventa[coloana] = vectorFrecventa[coloana] + matrice[linie][coloana];
	}
	int maxim = vectorFrecventa[0];
	int culoare = 0;
	for (int index = 1; index < nrColoane; index++)
		if (maxim < vectorFrecventa[index])
		{
			maxim = vectorFrecventa[index];
			culoare = index;
		}
	return culoare;
}

void InterschimbareLinii(int**& matrice, int linie, int linie1, int nrColoane)
{
	for (int coloana = 0; coloana < nrColoane; coloana++)
	{
		int aux = matrice[linie][coloana];
		matrice[linie][coloana] = matrice[linie1][coloana];
		matrice[linie1][coloana] = aux;
	}
}

void SortareK(int**& matrice, const int& nrLinii, const int& nrColoane, const int& k)
{
	for(int linie=0;linie<nrLinii;linie++)
	 for(int linie1=linie+1;linie1<nrLinii;linie1++)
		 if (matrice[linie][k] < matrice[linie1][k])
		 {
			 InterschimbareLinii(matrice, linie, linie1, nrColoane);
		 }
}

void Interschimbare(int& nr1, int& nr2)
{
	int aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}

void SortareLinie(int**& matrice, const int& linie, const int& nrColoane)
{
	for (int coloana = 0; coloana < nrColoane; coloana++)
		for (int coloana1 = coloana + 1; coloana1 < nrColoane; coloana1++)
			if (matrice[linie][coloana] > matrice[linie][coloana1])
				Interschimbare(matrice[linie][coloana], matrice[linie][coloana1]);
}

void VerifFibonacci(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	std::ofstream FisierIesire("Fisier.out");
	for (int linie = 0; linie < nrLinii; linie++)
	{
		SortareLinie(matrice, linie, nrColoane);
		int ok = 1;
		for (int coloana = 2; coloana < nrColoane; coloana++)
			if (matrice[linie][coloana] != matrice[linie][coloana - 1] + matrice[linie][coloana - 2])
			{
				ok = 0;
				break;
			}
		if (ok == 1)
		   FisierIesire << linie << ' ';
	}
	FisierIesire.close();
}

void AfisareMatrice(int**& matrice, const int& nrLinii, const int& nrColoane)
{
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane; coloana++)
			std::cout << matrice[linie][coloana] << ' ';
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
	int n, m,k;
	std::ifstream FisierIntrare("Fisier.in");
	FisierIntrare >> n >> m>>k;
	if (Validare(n, m) == false)
	{
		std::cout << "Matricea nu este valida" << std::endl;
		return 0;
	}
	int** matrice = {};
	AlocareDinamica(matrice, n, m);
	CitireMatrice(matrice, n, m);
	std::cout<<"Cea mai intalnita culoare este cea cu indexul "<<CeaMaiIntalnitaCuloare(matrice, n, m)<<std::endl;
	VerifFibonacci(matrice, n, m);
	SortareK(matrice, n, m, k);
	AfisareMatrice(matrice, n, m);
	DealocareDinamica(matrice, n);
	FisierIntrare.close();
	return 0;
}