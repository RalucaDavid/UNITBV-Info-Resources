#include <iostream>

void Interschimbare(int& element1, int& element2)
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
	return index - 1;
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

int main()
{

	return 0;
}