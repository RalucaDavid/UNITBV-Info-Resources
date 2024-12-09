#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool CitireDate(std::vector<int>& timpii, int& nrMasini, int& timpDeLucru)
{
	std::ifstream fin("FisierProblema3.intrare");
	fin >> nrMasini >> timpDeLucru;
	if (nrMasini < 0)
	{
		std::cout << "Numarul de masini este invalid!" << std::endl;
		fin.close();
		return false;
	}
	int element;
	for (int index = 0; index < nrMasini; index++)
	{
		fin >> element;
		timpii.push_back(element);
	}
	fin.close();
	return true;
}

int AflareNumarMaximMasini(std::vector<int>& timpii, const int& nrMasini, int timpDeLucru)
{
	int nrMaxMasini = 0;
	std::sort(timpii.begin(), timpii.end());
	for (int index = 0; index < nrMasini; index++)
	{
		if (timpii[index] > timpDeLucru)
			index = nrMasini;
		else
		{
			timpDeLucru = timpDeLucru - timpii[index];
			nrMaxMasini++;
		}
	}
	return nrMaxMasini;
}

int main()
{
	int nrMasini = 0, timpDeLucru = 0;
	std::vector<int> timpii;
	if (CitireDate(timpii, nrMasini, timpDeLucru))
	{
		std::cout << "Numarul maxim de masini este:" << AflareNumarMaximMasini(timpii, nrMasini, timpDeLucru) << std::endl;
	}
	return 0;
}