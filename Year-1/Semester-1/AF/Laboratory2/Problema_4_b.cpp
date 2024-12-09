#include <iostream>

void CitireTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void MutareKPoz(const int &n,int tablou[], int k)
{
	while (k > 0)
	{
		int aux = tablou[n - 1];
		for (int index = n - 1; index > 0; index--)
			tablou[index] = tablou[index - 1];
		tablou[0] = aux;
		k--;
	}
}
void AfisareTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cout << tablou[index] << " ";
}
int main()
{
	int n,k;
	std::cout << "Introduceti dimensiunea vectorului si k:";
    std::cin >> n>>k;
	int* tablou = new int[n];
	std::cout << "Introduceti elementele vectorului:";
	CitireTablou(tablou,n);
	MutareKPoz(n,tablou,k);
	AfisareTablou(tablou,n);
	delete[] tablou;
	return 0;
}