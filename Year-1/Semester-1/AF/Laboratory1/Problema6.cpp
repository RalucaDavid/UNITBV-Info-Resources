#include <iostream>
void aparitieCifra(int n, int c)
{
	while (n > 0)
	{
		if (n % 10 == c)
			std::cout << c;
		n = n / 10;
	}
}
void numarNou(int n)
{
	for (int i = 1; i <= 9; i++)
		aparitieCifra(n, i);
}
int main()
{
	int n;
	std::cin >> n;
	numarNou(n);
	return 0;
} 