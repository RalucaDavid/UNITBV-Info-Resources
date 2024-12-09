#include <iostream>

int NrCifre(int nr)
{
	if (nr == 0)
		return 1;
	int cate = 0;
	while (nr > 0)
	{
		nr = nr / 10;
		cate++;
	}
	return cate;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << NrCifre(n);
	return 0;
}