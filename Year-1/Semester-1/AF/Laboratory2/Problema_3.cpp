#include<iostream>

void FacereLoc(int& n, int tablou[], int pozitie)
{
	n++;
	for (int index = n - 1; index > pozitie; index--)
		tablou[index] = tablou[index - 1];
	tablou[pozitie] = 0;
}
void SumaProdus(int a, int b, int& suma, int& produs)
{
	suma = a + b;
	produs = a * b;
}
void CitireTablou(const int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void InserareSumProd(int& n, int tablou[])
{
	for (int index = 0; index < n - 1; index++)
	{
		FacereLoc(n, tablou, index + 1);
		FacereLoc(n, tablou, index + 2);
		int suma, produs;
		SumaProdus(tablou[index], tablou[index + 3], suma, produs);
		tablou[index + 1] = suma;
		tablou[index + 2] = produs;
		index = index + 2;
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
	int* tablou = new int[3*n];
	std::cout << "Introduceti elementele vectorului:";
	CitireTablou(n, tablou);
	InserareSumProd(n, tablou);
	AfisareTablou(n, tablou);
	delete[] tablou;
	return 0;
}