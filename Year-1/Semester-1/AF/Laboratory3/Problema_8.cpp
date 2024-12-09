#include <iostream>
#include <vector>

void CitireMatrice(std::vector<std::vector<int>>& matrice, int& n)
{
	std::cout << "Introduceti dimensiunea matricei:";
	std::cin >> n;
	std::cout << "Introduceti elementele matricei:" << std::endl;
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
	std::cout << std::endl;
}
void AfisareSerpuireMatrice(std::vector<std::vector<int >>& matrice, const int& n)
{
	int nrDiagonala=0,index,index2;
	int linie = 0, coloana = 0;
	while (linie+coloana<2*n)
	{
		if (nrDiagonala % 2 == 0)
		{
			index = 0;
			index2 = coloana;
			while ((index <= linie) && (index2 >= 0))
			{
				std::cout << matrice.at(index).at(index2) << ' ';
				index++;
				index2--;
			}
		}
		else
		{
			index = linie;
			index2 = 0;
			while ((index>=0)&&(index2<=coloana))
			{
				std::cout << matrice.at(index).at(index2) << ' ';
				index--;
				index2++;
			}
		}
		nrDiagonala++;
		linie++;
		coloana++;
	}
	linie = 1;
	coloana = 1;
	while (linie + coloana <= 2 * n)
	{
		if (nrDiagonala % 2 == 1)
		{
			index = n - 1;
			index2 = coloana;
			while ((index >= linie) && (index2 <= n-1))
			{
				std::cout << matrice.at(index).at(index2) << ' ';
				index--;
				index2++;
			}
		}
		else
		{
			index = linie;
			index2 = n-1;
			while ((index <=n-1) && (index2 >=coloana))
			{
				std::cout << matrice.at(index).at(index2) << ' ';
				index++;
				index2--;
			}
		}
		nrDiagonala++;
		linie++;
		coloana++;
	}
}
int main()
{
	std::vector<std::vector<int>> matrice;
	int n;
	CitireMatrice(matrice, n);
	AfisareSerpuireMatrice(matrice, n);
	return 0;
}