#include <iostream>

void AlocareVector(float*&vector,int n)
{
	vector = new float[n];
}

void CitireVector(float* vector, int n)
{
	std::cout << "Introduceti elementele:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cin >> vector[i];
}

void AdaugareEl(float*& vector, int &n)
{
	float* vector2;
	for (int i = 1; i < n-1; i++)
	{
		n++;
		AlocareVector(vector2, n);
		vector = vector2;
		for(int j = n; j > i; j++)
			vector[j] = vector[j - 1];
		vector[i] =(vector[i - 1] + vector[i + 1]) / 2;
		delete[] vector2;
	}
}

void AfisareVector(float*vector,int n)
{
	for (int i = 0; i < n; i++)
		std::cout << vector[i] << ' ';
}

int main()
{
	int n;
	float* vector;
	std::cout << "Introduceti dimensiunea:" << std::endl;
	std::cin >> n;
	AlocareVector(vector, n);
	CitireVector(vector, n);
	AdaugareEl(vector, n);
	AfisareVector(vector, n);
	delete[] vector;
	return 0;
}
