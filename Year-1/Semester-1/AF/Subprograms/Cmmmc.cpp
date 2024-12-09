#include <iostream>

int Cmmdc(int nr1, int nr2)
{
	int aux = nr1;
	int aux2 = nr2;
	while (nr1!=nr2)
	{
		if (nr1 < nr2)
			nr1 = nr1 + aux;
		else
			nr2 = nr2 + aux2;
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