#include <iostream>
#include <math.h>

void DivizoriNr(int nr)
{
	for (int d = 1; d <= std::sqrt(nr); d++)
		if (nr % d == 0);
		  //ceva
	// sau 
	for (int d = 1; d * d <= nr; d++)
		if (nr % d == 0);
}
int main()
{

}