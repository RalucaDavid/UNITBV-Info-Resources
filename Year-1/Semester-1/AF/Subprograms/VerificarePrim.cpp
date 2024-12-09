#include <iostream>
#include <math.h>

int VerifNrPrim(int nr)
{
	if (nr <= 1)
		return 0;
	for (int d = 2; d <= std::sqrt(nr); d++)
		if (nr % d == 0)
			return 0;
	return 1;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << VerifNrPrim(n);
	return 0;
}