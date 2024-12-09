#include <iostream>
int cmmdc(int a, int b)
{
	while (a != 0)
	{
		int r = b % a;
		b = a;
		a = r;
	}
	return b;
}
void pereche(int n)
{
	int a, b,Max=0,nr1,nr2;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a >> b;
		if (cmmdc(a, b) > Max)
		{
			Max = cmmdc(a,b);
			nr1 = a;
			nr2 = b;
		}
	}
	std::cout << nr1 << ' ' << nr2;
}
int main()
{
	int n;
	std::cin >> n;
	pereche(n);
	return 0;
}