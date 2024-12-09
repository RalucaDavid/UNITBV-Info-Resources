#include <iostream>
#include <vector>

void CitireMatrice(std::vector<std::vector<int>>& matrice, int& n)
{
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	std::cout << "Introduceti elementele:" << std::endl;
	int element;
	for (int linie = 0; linie < n; linie++)
	{
		std::vector<int> vectorLinie;
		for (int coloana = 0; coloana < n; coloana++)
		{
			std::cin >> element;
			vectorLinie.push_back(element);
		}
		matrice.push_back(vectorLinie);
	}
}
void FormareVectorFrecventa(std::vector<int>& vectorFrecventa,int n)
{
	for (int index = 0; index < n * n; index++)
		vectorFrecventa.push_back(0);
}
int VerifMatrice(std::vector < std::vector<int>>& matrice, const int& n)
{
	std::vector<int> vectorFrecventa;
	FormareVectorFrecventa(vectorFrecventa, n);
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < n; coloana++)
			vectorFrecventa.at(matrice.at(linie).at(coloana))++;
	for (int index = 0; index < n * n; index++)
		if (vectorFrecventa[index] == 0)
			return 0;
	return 1;
}
int main()
{
	std::vector<std::vector<int>> matrice;
	int n;
	CitireMatrice(matrice, n);
	std::cout<<VerifMatrice(matrice, n);
	return 0;
}