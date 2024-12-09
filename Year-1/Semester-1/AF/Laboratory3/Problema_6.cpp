#include <iostream>
#include <vector>

void CitireMatrice(std::vector<std::vector<int>>& matrice, int& n)
{
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	std::cout <<"Introduceti elementele matricei:" << std::endl;
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
void InterElemSimDP(std::vector<std::vector<int>>& matrice, const int& n)
{
	for (int linie = 0; linie < n; linie++)
		for (int coloana = 0; coloana < linie; coloana++)
			if (matrice.at(linie).at(coloana) % 2 == matrice.at(coloana).at(linie) % 2)
				Interschimbare(matrice.at(linie).at(coloana), matrice.at(coloana).at(linie));
}
void AfisareMatrice(std::vector<std::vector<int>>& matrice, const int& n)
{
	std::cout << std::endl;
	for (int linie = 0; linie < n; linie++)
	{
		for (int coloana = 0; coloana < n; coloana++)
			std::cout << matrice.at(linie).at(coloana)<<' ';
		std::cout << std::endl;
	}
}
int main()
{
	std::vector<std::vector<int>> matrice;
	int n;
	CitireMatrice(matrice, n);
	InterElemSimDP(matrice, n);
	AfisareMatrice(matrice, n);
	return 0;
}