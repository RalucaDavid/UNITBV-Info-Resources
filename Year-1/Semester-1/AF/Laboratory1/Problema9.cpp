#include<iostream>
int NrNou(int n)
{
	int aux = 0, p = 1;
	while (n > 9)
	{
		aux = aux + n % 10 * p * 10 + n / 10 % 10 * p;
		n = n / 100;
		p = p * 100;
	}
	return aux;
}
int main()
{
	int n;
	std::cin >> n;
	std::cout << NrNou(n);
	return 0;
}