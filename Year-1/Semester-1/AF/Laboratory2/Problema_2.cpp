#include <iostream>
#include <math.h>

void EliminareElement(int& n, int tablou[], int& pozitie)
{
	for (int index = pozitie; index < n - 1; index++)
		tablou[index] = tablou[index + 1];
	n--;
	pozitie--;
}
void CitireTablou(const int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void ElemSumaVecini(int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
	{
		if ((index == 0) && (tablou[index] == tablou[index + 1]))
			EliminareElement(n, tablou, index);
		else if ((index == n - 1) && (tablou[index] == tablou[index - 1]))
			EliminareElement(n, tablou, index);
		else if (tablou[index] == tablou[index - 1] + tablou[index + 1])
			EliminareElement(n, tablou, index);

	}
}
void AfisareTablou(const int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
		std::cout << tablou[index] << ' ';
}
int main()
{
	int n;
	std::cout << "Introduceti dimensiunea vectorului:";
    std::cin >> n;
	int* tablou = new int[n];
	std::cout << "Introduceti elementele vectorului:";
	CitireTablou(n, tablou);
	ElemSumaVecini(n, tablou);
	AfisareTablou(n, tablou);
	delete[] tablou;
	return 0;
}