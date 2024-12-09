#include <iostream>

void CitireTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void MutareKPoz(int &n,int tablou[],int k)
{
	int aux = 0;
	while (aux!=k)
	{
		n++;
		for (int index = n - 1; index > aux; index--)
			tablou[index] = tablou[index - 1];
		tablou[aux] = 0;
		aux++;
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
	int* tablou = new int[n+k];
	std::cout << "Introduceti elementele vectorului:";
	CitireTablou(tablou,n);
	MutareKPoz(n,tablou, k);
	AfisareTablou(tablou,n);
	delete[] tablou;
	return 0;
}