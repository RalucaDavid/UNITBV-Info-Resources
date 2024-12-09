#include <iostream>

void DescompunereFactPrimi(int nr)
{
	int d = 2,putere;
	while (nr>1)
	{
		putere = 0;
		while (nr % d == 0)
		{
			nr = nr / d;
			putere++;
		}
		//ceva
		d++;
		if ((nr>1) && (d * d > nr))
			nr = d;
	}
}

int main()
{

	return 0;
}