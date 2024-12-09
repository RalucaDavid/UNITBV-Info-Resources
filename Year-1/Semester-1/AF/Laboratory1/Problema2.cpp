#include <iostream>
int rasturnat(int nr)
{
	int aux = 0;
	while (nr > 0)
	{
		aux = aux * 10 + nr % 10;
		nr = nr / 10;
	}
	return aux;
}
int verificareRasturnat(int n)
{
	int primulNr,nr,total=0;
	std::cin >> primulNr;
	for (int i = 1; i < n; i++)
	{
		std::cin >> nr;
		if (primulNr == rasturnat(nr))
			total++;
	}
	return total;
}
int main()
{
    int n;
    std::cin>>n;
    std::cout<<verificareRasturnat(n);
    return 0;
}