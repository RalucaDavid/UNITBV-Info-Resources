#include<iostream>

void CitireTablou(float tablou[], const int& n)
{
	std::cout << "Introduceti elementele vectorului:";
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void AfisareStatistica(const int& m, int intervale[])
{
	std::cout << "Numarul mediilor cuprinse in intervalul [1,2] este " << intervale[1] + intervale[2] << std::endl;
	for (int index = 3; index < m; index++)
		std::cout << "Numarul mediilor cuprinse in intervalul (" << index - 1 << "," << index << "] este " << intervale[index] << std::endl;
}
void Statistica(const int& n, float tablou[])
{
	int m;
	std::cout << "Introduceti cel mai mare capat al intervalelor:";
	std::cin >> m;
	int* intervale = new int[m+1];
	for (int index = 0; index < m + 1; index++)
		intervale[index] = 0;
	for (int index = 0; index < n; index++)
	{
		intervale[int(tablou[index]+1)]++;
	}
	AfisareStatistica(m+1, intervale);
	delete[] intervale;
}
int main()
{
	int n;
	std::cout << "Introduceti dimensiunea vectorului:";
	std::cin >> n;
	float* tablou = new float[n];
	CitireTablou(tablou, n);
	Statistica(n, tablou);
	delete[] tablou;
	return 0;
}