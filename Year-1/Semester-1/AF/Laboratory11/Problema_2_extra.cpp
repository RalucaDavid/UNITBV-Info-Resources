#include <iostream>
#include <fstream>

bool CitireDate(int& nrStatiTotal,int& distantaMin,int*& distanteStati)
{
	std::ifstream fin("FisierProblema2.intrare");
	fin >> nrStatiTotal>>distantaMin;
	if (nrStatiTotal < 0)
	{
		fin.close();
		std::cout << "Numarul de statii de autobuz este invalid" << std::endl;
		return false;
	}
	distanteStati = new int[nrStatiTotal-1];
	for (int index = 0; index < nrStatiTotal - 1; index++)
		fin >> distanteStati[index];
	fin.close();
	return true;
}

void AflareStati(const int& nrStatiTotal,const int& distantaMin,int*& distanteStati)
{
	int nrStati = 1, sumaDistanta = 0;
	int* stati = new int[nrStatiTotal];
	stati[nrStati-1] = 1;
	for (int index = 0; index < nrStatiTotal - 1; index++)
	{
		sumaDistanta = sumaDistanta+distanteStati[index];
		if (sumaDistanta >= distantaMin)
		{
			nrStati++;
			stati[nrStati - 1] = index+2;
			sumaDistanta = 0;
		}
	}
	std::cout << "Numarul de stati este " << nrStati << std::endl;
	std::cout << "Statiile sunt: " << std::endl;
	for (int index = 0; index < nrStati; index++)
		std::cout << stati[index] << ' ';
}

int main()
{
	int nrStatiTotal = 0, distantaMin=0;
	int* distanteStati = {};
	if (CitireDate(nrStatiTotal,distantaMin,distanteStati))
	{
		AflareStati(nrStatiTotal, distantaMin, distanteStati);
	}
	return 0;
}