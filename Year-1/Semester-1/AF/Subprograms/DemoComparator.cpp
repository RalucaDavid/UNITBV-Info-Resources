#include <iostream>
#include <fstream>


void CitireVector(int*& vector, int& dimensiune)
{
	std::ifstream fisier("fisier.in");
	fisier >> dimensiune;
	vector = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++)
	{
		fisier >> vector[i];
	}
	fisier.close();
}

void AfisareVector(int*& vector, const int& dimensiune)
{
	for (int i = 0; i < dimensiune; i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void DealocareVector(int*& vector, const int& dimensiune)
{
	delete[] vector;
}


void Interschimbare(int& element1, int& element2)
{
	int auxiliar = element1;
	element1 = element2;
	element2 = auxiliar;
}

struct ComparatorCrescator {
	bool operator()(int a, int b)
	{
		return a <= b;
	}
};

struct ComparatorDescrescator {
	bool operator()(int a, int b)
	{
		return a >= b;
	}
};

struct data {
	int zi, luna, an;
};

struct ComparatorData {
	bool operator()(data a, data b)
	{
		if (a.an <= b.an)
		{
			if (a.luna <= b.luna)
			{
				return true;
			}
		}
	}
};

template <typename T>
int Partitie(int*& vector, int indexStart, int indexFinal, T comparator)
{
	int pivot = vector[indexFinal];
	int index = indexStart; // -> interschimbari
	for (int contor = indexStart; contor <= indexFinal; contor++)
	{
		if (comparator(vector[contor],pivot))
		{
			Interschimbare(vector[index], vector[contor]);
			index++;
		}

	}
	return index - 1;
}

template <typename T>
void QuickSort(int*& vector, int indexStart, int indexFinal, T tip)
{
	//O(n*log n)
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = Partitie(vector, indexStart, indexFinal, tip);
		QuickSort(vector, indexStart, partitie - 1, tip);
		QuickSort(vector, partitie + 1, indexFinal, tip);
	}
}

int main()
{
	int* vector = {};
	int dimensiune = 0;
	CitireVector(vector, dimensiune);
	QuickSort(vector, 0, (dimensiune - 1) / 2, ComparatorCrescator());
	QuickSort(vector, (dimensiune - 1) / 2 + 1, dimensiune - 1, ComparatorDescrescator());
	AfisareVector(vector, dimensiune);
	DealocareVector(vector, dimensiune);
}