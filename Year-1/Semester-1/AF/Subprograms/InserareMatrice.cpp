#include <fstream>

void AlocareDinamica(int**& matrice, int& linii, int &coloane)
{
	matrice = new int*[linii];
	for (int index = 0; index < linii; index++) {
		matrice[index] = new int[coloane];
	}
	 
}

void DealocareDinamica(int**& matrice, int linii)
{
	for (int index = 0; index < linii; index++)
		delete[] matrice[index];
	delete[] matrice;
}

void citire(int**& matrice, int& linii, int& coloane)
{
	std::ifstream fisierintrare("Fisier.in");
	fisierintrare >> linii;
	fisierintrare >> coloane;
	AlocareDinamica(matrice,linii,coloane);
	for (int index = 0; index <linii; index++)
		for (int index2 = 0; index2 < coloane; index2++)
			fisierintrare >> matrice[index][index2];
	fisierintrare.close();
}

void afisare(int**& matrice, int& linii, int& coloane)
{
	std::ofstream fisieriesire("infisier.out");
	for (int index = 0; index < linii; index++) {
		for (int index2 = 0; index2 < coloane; index2++)
			fisieriesire << matrice[index][index2] << " ";
		fisieriesire << std::endl;
	}
	fisieriesire.close();
}

void stergere(int**& matrice, int& linii, int& coloane, int& pozitie)
{
	for (int i = pozitie; i < linii - 1; i++)
	{
		for (int j = 0; j < coloane; j++)
		matrice[i][j] = matrice[i+1][j];
	}
	linii--;
}

int main()
{
	int** matrice = {};
	int linii, coloane;
	int element = 9, pozitie = 1;
	citire(matrice, linii,coloane);
	//inserare(vector, dimensiune, element, pozitie);
	stergere(matrice,linii,coloane,pozitie);
	afisare(matrice, linii,coloane);
	DealocareDinamica(matrice,linii);
}