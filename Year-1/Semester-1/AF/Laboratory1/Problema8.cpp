#include <iostream>
int eliminareCif(int n,int c)
{
	if (n > 0)
	{
		if (n % 10 != c)
		   return n % 10 + 10 * eliminareCif(n / 10, c);
		return eliminareCif(n / 10, c);
	}
	return 0;
}
int main()
{
	int n,c;
	std::cin >> n>>c;
	std::cout<<eliminareCif(n,c);
	return 0;
} 