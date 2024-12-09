#include <fstream>

void AlocareDinamica(int*& vector, int& dimensiune)
{
	vector = new int[dimensiune];
}

void DealocareDinamica(int*& vector)
{
	delete[] vector;
}

void citire(int*& vector, int& dimensiune)
{
	std::ifstream fisierintrare("infisier.in");
	fisierintrare >> dimensiune;
	AlocareDinamica(vector, dimensiune);
	for(int index=0;index<dimensiune;index++)
		fisierintrare >> vector[index];
	fisierintrare.close();
}

void afisare(int*& vector, int& dimensiune)
{
	std::ofstream fisieriesire("infisier.out");
	for (int index = 0; index < dimensiune; index++)
		fisieriesire << vector[index]<<" ";
	fisieriesire.close();
}

void inserare(int*& vector, int& dimensiune, int& element, int& pozitie)
{
	int nouadimensiune=dimensiune+1;
	int* vectorsecundar=new int [nouadimensiune];
	for (int index = 0; index < nouadimensiune; index++)
	{
		if (index < pozitie)
			vectorsecundar[index] = vector[index];
		else if (index == pozitie)
			vectorsecundar[index] = element;
		else vectorsecundar[index] = vector[index - 1];
	}
	vector = vectorsecundar;
	dimensiune = nouadimensiune;
}

void stergere(int*& vector, int& dimensiune, int& pozitie)
{
	for (int i = pozitie; i < dimensiune-1; i++)
	{
		vector[i] = vector[i + 1];
	}

	dimensiune--;
}

int main()
{
	int* vector={};
	int dimensiune=0,element=9,pozitie=3;
	citire(vector, dimensiune);
	inserare(vector, dimensiune, element, pozitie);
	stergere(vector, dimensiune, pozitie);
	afisare(vector, dimensiune);
	DealocareDinamica(vector);
}