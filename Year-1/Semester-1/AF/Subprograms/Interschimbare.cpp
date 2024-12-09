#include <iostream>

void Interschimbare(int& nr1, int& nr2)
{
	int aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}
int main()
{
	int a, b;
	std::cin >> a >> b;
	Interschimbare(a, b);
	std::cout << a <<' '<<b;
	return 0;
}