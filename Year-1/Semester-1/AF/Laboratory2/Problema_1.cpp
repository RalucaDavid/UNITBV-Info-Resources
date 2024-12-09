#include <iostream>
#include <math.h> 

int Cmmcf(int nr)
{
	int MIN = 9;
	while (nr)
	{
		if (nr % 10 < MIN)
			MIN = nr % 10;
		nr = nr / 10;
	}
	return MIN;
}
int VerifPrim(int nr)
{
	if (nr <= 1)
		return 0;
	else
	{
		for (int d = 2; d <= sqrt(nr); d++)
			if (nr % d == 0)
				return 0;
	}
	return 1;
}
void CitireTablou(const int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
		std::cin >> tablou[index];
}
void InlocuireElemente(const int& n, int tablou[])
{
	for (int index = 0; index < n; index++)
	{
		if (index % 2 == 0)
		   tablou[index] = Cmmcf(tablou[index]);
		else
		   tablou[index] = VerifPrim(tablou[index]);
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
	InlocuireElemente(n, tablou);
	AfisareTablou(n, tablou);
	delete[] tablou;
	return 0;
}