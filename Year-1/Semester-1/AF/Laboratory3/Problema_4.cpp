#include <iostream>
#include <vector>

void CitireMatrice(std::vector<std::vector<int>>& matrice,int& n)
{
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	std::cout << "Introduceti elementele matricei:"<<std::endl;
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
void Interschimbare(int& nr1, int& nr2)
{
	int aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}
void InterLinii(std::vector<std::vector<int>>& matrice,const int&linie,const int&linie1, const int& n)
{
	for (int coloana = 0; coloana < n; coloana++)
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie1).at(coloana));
}
void InterColoane(std::vector<std::vector<int>>& matrice, const int& coloana, const int& coloana1, const int& n)
{
	for (int linie = 0; linie < n; linie++)
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie).at(coloana1));
}
void OrdonareElemDP(std::vector<std::vector<int>>& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
		for (int linie1 = linie + 1; linie1 < n; linie1++)
			if (matrice.at(linie).at(linie) > matrice.at(linie1).at(linie1))
			{
				InterLinii(matrice, linie, linie1, n);
				InterColoane(matrice, linie, linie1, n);
			}
}
void AfisareMatrice(const std::vector<std::vector<int>>& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
	{
		for (int coloana = 0; coloana < n; coloana++)
			std::cout << matrice.at(linie).at(coloana)<<" ";
		std::cout << std::endl;
	}
}
int main()
{
	std::vector<std::vector<int>>matrice;
	int n;
	CitireMatrice(matrice, n);
	OrdonareElemDP(matrice, n);
	AfisareMatrice(matrice, n);
	return 0;
}