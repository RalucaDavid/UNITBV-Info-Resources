#include <iostream>
#include <stdlib.h>

int AlocareVector(int*& vector, int& dimensiune)
{
	std::cout << "Introduceti dimensiunea vectorului:";
	std::cin >> dimensiune;
	if (dimensiune < 0)
		return 0;
	vector = new int[dimensiune];
	return 1;
}

void AfisareVector(int*& vector, const int& dimensiune)
{
	for (int i = 0; i < dimensiune; i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void CitireVector(int*& vector, const int& dimensiune)
{
	for (int i = 0; i < dimensiune; i++)
	{
		vector[i] = rand();
	}
	std::cout << "Vectorul are elementele:" << std::endl;
	AfisareVector(vector, dimensiune);
}

void DealocareVector(int*& vector, const int& dimensiune)
{
	delete[] vector;
}

void Interschimbare(int& element1, int&element2)
{
	int auxiliar = element1;
	element1 = element2;
	element2 = auxiliar;
}

int Partitie(int*& vector, int indexStart, int indexFinal)
{
	int pivot = vector[indexFinal];
	int index = indexStart;
	for (int contor = indexStart; contor <= indexFinal; contor++)
		{
			if (vector[contor] <= pivot)
			{
				Interschimbare(vector[index], vector[contor]);
				index++;
			}
		}
	return index-1;
}

void QuickSort(int*& vector, int indexStart, int indexFinal)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = Partitie(vector, indexStart, indexFinal);
		QuickSort(vector, indexStart, partitie - 1);
		QuickSort(vector, partitie + 1, indexFinal);
	}
}

int PartitiePare(int*& vector, int indexStart, int indexFinal)
{
	int pivot = vector[indexFinal];
	int index = indexStart;
	for (int contor = index; contor <= indexFinal; contor++)
	{
		if (contor % 2 == 0)
		{
			Interschimbare(vector[contor], vector[index]);
			index++;
		}
	}
	return index - 1;
}

void QuickSortSeparareNr(int*& vector, int indexStart,int indexFinal)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = PartitiePare(vector, indexStart, indexFinal);
	    QuickSortSeparareNr(vector, indexStart, partitie - 1);
		QuickSortSeparareNr(vector, partitie + 1, indexFinal);
	}
}

void Sortare(int*& vector, int& dimensiune)
{
	int nrElemPozPare = (dimensiune+1)/2;
	QuickSortSeparareNr(vector,0,dimensiune-1);
	std::cout << "Vectorul cu numerele separate:"<<std::endl;
	AfisareVector(vector, dimensiune);
	QuickSort(vector, 0, nrElemPozPare-1);
	std::cout << "Vectorul dupa sortare:"<<std::endl;
	AfisareVector(vector, dimensiune);
}

int main()
{
	int* vector = {};
	int dimensiune = 0;
	if (AlocareVector(vector, dimensiune))
	{
		CitireVector(vector, dimensiune);
		Sortare(vector, dimensiune);
		DealocareVector(vector, dimensiune);
	}
	return 0;
}