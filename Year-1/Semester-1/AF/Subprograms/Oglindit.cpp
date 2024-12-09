#include <iostream>

int Oglindit(int nr)
{
	int ogl = 0;
	while (nr > 0)
	{
		ogl = ogl * 10 + nr % 10;
		nr = nr / 10;
	}
	return ogl;
}
int main()
{
	int n;
	std::cin >> n;
	std::cout << Oglindit(n);
	return 0;
}