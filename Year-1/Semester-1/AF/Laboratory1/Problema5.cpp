#include <iostream>
#include <math.h>
bool prim(int nr)
{
	if (nr <= 1)
	 return false;
	for (int d = 2; d <= sqrt(nr); d++)
	 if (nr % d == 0)
	   return false;
	return true;
}
void proprietate(int k)
{
        for (int i = pow(10, k - 1); i < pow(10, k); i = i + 2)
         if (prim(i - 1) && prim(i + 1))
	  std::cout << i << ' ';
}
int main()
{
	int k;
	std::cin >> k;
	proprietate(k);
	return 0;
} 