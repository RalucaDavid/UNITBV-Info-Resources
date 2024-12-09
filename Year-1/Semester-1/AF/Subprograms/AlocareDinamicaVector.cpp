#include <iostream>

void CitireVector(int vector[],const int& dimensiune)
{
	std::cout << "Introduceti elementele vectorului:"<<std::endl;
	for (int index = 0; index < dimensiune;index++)
		std::cin >> vector[index];
	std::cout << "Citirea s-a facut cu succes!"<<std::endl;
}

void AfisareVector(int vector[], const int& dimensiune)
{
	for (int index = 0; index < dimensiune; index++)
		std::cout << vector[index] << ' ';
	std::cout << std::endl;
}

int main()
{
	int n;
	std::cout << "Introduceti dimensiunea vectorului:";
	std::cin >> n;
	if (n < 0)
		return 0;
	int* vector = new int[n];
	CitireVector(vector, n);
	AfisareVector(vector, n);
	delete[] vector;
	return 0;
}