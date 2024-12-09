#include <iostream>
bool difCifConst(int n)
{
	while (n > 99)
	{
		if (n % 10 - n / 10 % 10 != n / 10 % 10 - n / 100 % 10)
			return false;
		n = n / 10;
	}
	return true;
}
void verifProgArit(int n)
{
	if (difCifConst(n))
		std::cout << "Cifrele lui " << n << " sunt in progresie aritmetuca";
	else
		std::cout << "Cifrele lui " << n << " nu sunt in progresie aritmetuca";
}
int main()
{
	int n;
	std::cin >> n;
	verifProgArit(n);
	return 0;
}