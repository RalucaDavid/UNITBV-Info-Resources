#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct proiecte
{
	int nrInvestitor, timp;
};

template <typename T>
bool CitireDate(std::vector<T>& listaProiecte, int& nrProiecte)
{
	std::ifstream fin("FisierProblema4.intrare");
	fin >> nrProiecte;
	if (nrProiecte < 0)
	{
		fin.close();
		std::cout << "Numarul de proiecte este invalid!" << std::endl;
		return false;
	}
	proiecte element;
	for (int index = 0; index < nrProiecte; index++)
	{
		fin >> element.timp;
		element.nrInvestitor = index + 1;
		listaProiecte.push_back(element);
	}
	fin.close();
	return true;
}

struct Comparator
{
	bool operator()(proiecte a,proiecte b)
	{
		return a.timp < b.timp;
	}
}comparator;

template <typename T>
void AflareOrdine(std::vector<T>& listaProiecte, int& nrProiecte)
{
	std::sort(listaProiecte.begin(),listaProiecte.end(),Comparator());
	std::cout << "Ordinea analizarii proiectelor este:" << std::endl;
	for (int index = 0; index < nrProiecte; index++)
		std::cout << listaProiecte[index].nrInvestitor << ' ';
}

int main()
{
	std::vector<proiecte> listaProiecte;
	int nrProiecte = 0;
	if (CitireDate(listaProiecte, nrProiecte))
	{
		AflareOrdine(listaProiecte, nrProiecte);
	}
	return 0;
}