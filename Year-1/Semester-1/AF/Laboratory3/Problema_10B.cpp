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
		{
		   vectorFrecventa.at(matrice.at(linie).at(coloana))++;
		   if (vectorFrecventa.at(matrice.at(linie).at(coloana)) >= 2)
			   return 0;
		}
	for (int index = 0; index < n * n; index++)
		if (vectorFrecventa[index] == 0)
			return 0;
	return 1;
}
int Pozitie0(std::vector<std::vector<int>>& matrice,const int& n, int&coloana)
{
	for(int linie=0;linie<n;linie++)
	 for(int coloana1=0;coloana1<n;coloana1++)
		 if (matrice.at(linie).at(coloana1) == 0)
		 {
			 coloana = coloana1;
			 return linie;
	     }
}
void Interschimbare(int& nr1, int& nr2)
{
	int aux = nr1;
	nr1 = nr2;
	nr2 = aux;
}
void AfisareMatrice(std::vector<std::vector<int>>& matrice, const int& n)
{
	std::cout << std::endl;
	for (int linie = 0; linie < n; linie++)
	{
		for (int coloana = 0; coloana < n; coloana++)
			std::cout << matrice.at(linie).at(coloana) << ' ';
		std::cout << std::endl;
	}
}
void MutareN(std::vector<std::vector<int>>& matrice,const int&n,int& linie, int& coloana)
{
	if (linie == 0)
		std::cout << "Nu se poate muta in N";
	else
	{
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie-1).at(coloana));
		AfisareMatrice(matrice, n);
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie - 1).at(coloana));
	}
}
void MutareS(std::vector<std::vector<int>>& matrice,const int&n, int&linie,int& coloana)
{
	if (linie == n-1)
		std::cout << "Nu se poate muta in S";
	else
	{
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie +1).at(coloana));
		AfisareMatrice(matrice, n);
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie +1).at(coloana));
	}
}
void MutareE(std::vector<std::vector<int>>& matrice,const int&n,int& linie,int& coloana)
{
	if (coloana== n-1)
		std::cout << "Nu se poate muta in E";
	else
	{
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie).at(coloana+1));
		AfisareMatrice(matrice, n);
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie).at(coloana+1));
	}
}
void MutareV(std::vector<std::vector<int>>& matrice,const int&n,int&linie,int& coloana)
{
	if (coloana==0)
		std::cout << "Nu se poate muta in V";
	else
	{
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie).at(coloana-1));
		AfisareMatrice(matrice, n);
		Interschimbare(matrice.at(linie).at(coloana), matrice.at(linie).at(coloana-1));
	}
}
void Mutare0(std::vector<std::vector<int>>& matrice, const int& n)
{
	int coloana = 0;
	int linie = Pozitie0(matrice, n,coloana);
	MutareN(matrice,n,linie,coloana);
	MutareS(matrice,n,linie,coloana);
	MutareE(matrice,n,linie,coloana);
	MutareV(matrice,n,linie,coloana);
}
int main()
{
	std::vector<std::vector<int>> matrice;
	int n;
	CitireMatrice(matrice, n);
	if (VerifMatrice(matrice, n) == 1)
		Mutare0(matrice, n);
	else
		std::cout << "Matricea nu este valida";
	return 0;
}