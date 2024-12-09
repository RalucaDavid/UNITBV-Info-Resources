#include <iostream>

void Fibonacci(int n)
{
	int nr1 = 1, nr2 = 1;
	for (int index = 3; index < n; index++)
	{
		int nr3 = nr1 + nr2;
		nr1 = nr2;
		nr2 = nr3;
	}
}

int main()
{

	return 0;
}