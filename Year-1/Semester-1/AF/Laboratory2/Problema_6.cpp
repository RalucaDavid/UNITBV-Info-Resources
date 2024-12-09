#include <iostream>

void CitireTablou(int tablou[],const int& n)
{
	std::cout << "Introduceti elementele vectorului:";
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void Reuniune(int n, int tablou[],int m, int tablou1[],int nm, int tablou2[])
{
	while ((n >= 0) && (m >=0))
	{
		if (tablou[n] > tablou1[m])
		{
			tablou2[nm] = tablou[n];
			n--;
			nm--;
		}
		else if (tablou1[m] > tablou[n])
		{
			tablou2[nm] = tablou1[m];
			m--;
			nm--;
		}
		else
		{
			tablou2[nm] = tablou[n];
			nm--;
			n--;
			tablou2[nm] = tablou1[m];
			nm--;
			m--;
		}
	}
	while (n >= 0)
	{
		tablou2[nm] = tablou[n];
		nm--;
		n--;
	}
	while (m >= 0)
	{
		tablou2[nm] = tablou1[m];
		nm--;
		m--;
	}
}
void AfisareTablou(int tablou[],const int& n)
{
	for (int index = 0; index < n; index++)
		std::cout << tablou[index] << " ";
}
int main()
{
	int n,m;
	std::cout << "Introduceti dimensiunea primului vectorului si celui de al doilea vector:";
    std::cin >> n>>m;
	int* tablou = new int[n];
	CitireTablou(tablou,n);
	int* tablou1 = new int[m];
	CitireTablou(tablou1, m);
	int* tablou2 = new int[m+n];
	Reuniune(n-1, tablou, m-1, tablou1,n+m-1,tablou2);
	AfisareTablou(tablou2,n+m);
	delete[] tablou;
	return 0;
}