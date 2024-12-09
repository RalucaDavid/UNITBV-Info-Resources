#include <iostream>

void CitireVector(int*& vector, int& dim)
{
	std::cout << "Introduceti elementele vectorului:";
	for(int index = 0; index < dim; index++)
		std::cin >> vector[index];
}

void Interschimbare(int& element1, int& element2)
{
	int auxiliar = element1;
	element1 = element2;
	element2 = auxiliar;
}

int Oglindit(int nr)
{
	int ogl = 0;
	while (nr != 0)
	{
		ogl = ogl * 10 + nr % 10;
		nr = nr / 10;
	}
	return ogl;
}

int Partitie(int*& vector, int& indexStart, int& indexFinal)
{
	int pivot = vector[indexFinal];
	int index = indexStart;
	for (int contor = index; contor <= indexFinal; contor++)
	{
		if (vector[contor] <= pivot)
		{
			Interschimbare(vector[index], vector[contor]);
			index++;
		}
	}
	return index - 1;
}

void QuickSort(int*& vector, int indexStart, int indexFinal)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie=Partitie(vector, indexStart, indexFinal);
		QuickSort(vector, indexStart, partitie - 1);
		QuickSort(vector, partitie + 1, indexFinal);
	}
}

int PartitiePal(int*& vector,int& indexStart, int& indexFinal)
{
	int pivot = vector[indexFinal];
	int index = indexStart;
	for (int contor = index; contor <= indexFinal; contor++)
	{
		if (vector[contor]==Oglindit(vector[contor]))
		{
			Interschimbare(vector[index], vector[contor]);
			index++;
		}
	}
	return index - 1;
}

void QuickSortSeparareNrPalindrom(int*& vector,int indexStart, int indexFinal)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = PartitiePal(vector, indexStart, indexFinal);
		QuickSortSeparareNrPalindrom(vector,indexStart, partitie - 1);
		QuickSortSeparareNrPalindrom(vector, partitie + 1, indexFinal);
	}
}

void Sortare(int*& vector, int& dim)
{
	int NrPal = 0;
	QuickSortSeparareNrPalindrom(vector, 0, dim-1);
	for (int index = 0; index < dim; index++)
	{
		if (vector[index] != Oglindit(vector[index]))
			break;
		NrPal++;
	}
	QuickSort(vector, 0, NrPal-1);
}

void AfisareVector(int*& vector, int& dim)
{
	for (int index = 0; index < dim; index++)
		std::cout << vector[index] << ' ';
}

int main()
{
	int dim;
	std::cout << "Introduceti dimensiunea vectorului:";
	std::cin >> dim;
	if (dim < 0)
	{
		std::cout << "Dimensiunea este invalida!" << std::endl;
		return 0;
	}
	else
	{
		int* vector = new int[dim];
		CitireVector(vector, dim);
		Sortare(vector, dim);
		AfisareVector(vector, dim);
		delete[] vector;
	}
	return 0;
}