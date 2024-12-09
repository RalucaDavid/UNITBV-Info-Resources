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
void SumCelor4Triunghiuri(const std::vector<std::vector<int>>& matrice, const int& n)
{
	int SumTN = 0, SumTV = 0, SumTS = 0, SumTE = 0;
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < n; coloana++)
		{
			if ((linie < coloana) && (linie + coloana < n - 1))
				SumTN = SumTN + matrice.at(linie).at(coloana);
			else if ((linie > coloana) && (linie + coloana < n - 1))
				SumTV = SumTV + matrice.at(linie).at(coloana);
			else if ((linie > coloana) && (linie + coloana > n - 1))
				SumTS = SumTS + matrice.at(linie).at(coloana);
			else if ((linie < coloana) && (linie + coloana > n - 1))
				SumTE = SumTE + matrice.at(linie).at(coloana);
		}
	std::cout << "Suma triunghiului nordic este " << SumTN << std::endl;
	std::cout << "Suma triunghiului vestic este " << SumTV << std::endl;
	std::cout << "Suma triunghiului sudic este " << SumTS << std::endl;
	std::cout << "Suma triunghiului estic este " << SumTE << std::endl;
}
int main()
{
	std::vector<std::vector<int>>matrice;
	int n;
	CitireMatrice(matrice, n);
	SumCelor4Triunghiuri(matrice, n);
	return 0;
}