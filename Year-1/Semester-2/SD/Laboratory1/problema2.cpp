#include <iostream>

void AlocareMatrice(int**& matrice, int n)
{
	matrice = new int* [n];
	for (int i = 0; i < n; i++)
		matrice[i] = new int[i];
}

void FormareMatrice(int**& matrice, int n)
{
	for(int i=0;i<n;i++)
	  for (int j = 0; j <= i; j++)
		{
		  if (j == 0)
			  matrice[i][j] = i;
		  else
			  matrice[i][j] = matrice[i][j - 1] + 1;
	    }
}

void AfisareMatrice(int** matrice, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << matrice[i][j] << ' ';
		std::cout << std::endl;
	}
}

int main()
{
	int** matrice;
	int n;
	std::cout << "Introduceti dimensiunea:" << std::endl;
	std::cin >> n;
	AlocareMatrice(matrice, n);
	FormareMatrice(matrice, n);
	AfisareMatrice(matrice, n);
	return 0;
}