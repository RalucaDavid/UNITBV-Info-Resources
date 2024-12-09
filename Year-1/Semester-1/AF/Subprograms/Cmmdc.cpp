#include <iostream>

int Cmmdc(int nr1, int nr2)
{
	while (nr2 > 0)
	{
		int rest = nr1 % nr2;
		nr1 = nr2;
		nr2 = rest;
	}
	return nr1;
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << Cmmdc(a, b);
	return 0;
}