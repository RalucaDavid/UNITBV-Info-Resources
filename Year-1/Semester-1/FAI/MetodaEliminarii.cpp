#include <iostream>
#include <fstream>
#include <vector>

bool CitireMatrice(std::vector<std::vector<double>>& matrice,int& nrLinii,int&nrColoane)
{
	std::ifstream fin("Fisier.in");
	if (!fin.is_open())
	{
		std::cout << "Fisierul nu exista sau nu s-a putut deschide!" << std::endl;
		fin.close();
		return false;
	}
	fin >> nrLinii >> nrColoane;
	if ((nrLinii < 0) || (nrColoane < 0))
	{
		std::cout << "Una sau ambele dimensiuni sunt invalide!" << std::endl;
		fin.close();
		return false;
	}
	int element;
	std::vector<double> vectorColoane;
	for (int index=0; index < nrLinii; index++)
	{
		vectorColoane.clear();
		for (int index2 = 0; index2 < nrColoane; index2++)
		{
			if (fin.eof())
			{
				std::cout << "Matricea nu are suficiente elemente!" << std::endl;
				fin.close();
				return false;
			}
			fin >> element;
			vectorColoane.push_back(element);
		}
		matrice.push_back(vectorColoane);
	}
	fin.close();
	return true;
}

void AfisareMatrice(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	std::cout << std::endl;
	for (int index = 0; index < nrLinii; index++)
	{
		for (int index2 = 0; index2 < nrColoane; index2++)
			std::cout << matrice[index][index2] << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void InterschimbareLinii(std::vector<std::vector<double>>& matrice,const int& linie1,const int& linie2,int nrLinii,int nrColoane)
{
	std::cout << "Interschimbam linia " << linie1+1 << " cu linia " << linie2+1 << std::endl;
	int aux;
	for (int index = 0; index < nrColoane; index++)
	{
		aux = matrice[linie1][index];
		matrice[linie1][index] = matrice[linie2][index];
		matrice[linie2][index] = aux;
	}
	std::cout << std::endl;
}

void InmultireLinie(std::vector<std::vector<double>>& matrice, const int& linie,double numar,int nrLinii,int nrColoane)
{
	std::cout << "Inmultim linia " << linie+1<<" cu "<<numar << std::endl;
	for (int index = 0; index < nrColoane; index++)
	{
		if(matrice[linie][index]!=0)
		 matrice[linie][index] = matrice[linie][index] * numar;
	}
	std::cout << std::endl;
}

void AdunareLinii(std::vector<std::vector<double>>& matrice, const int& linie1, const int& linie2, double numar,int nrLinii,int nrColoane)
{
	std::cout << "Adunam linia " << linie1+1 << " cu "<<-1*numar<<" * linia " << linie2+1 << std::endl;
	for (int index = 0; index < nrColoane; index++)
	{
		   matrice[linie1][index] = matrice[linie1][index] + -1 * numar * matrice[linie2][index];
	}
	std::cout << std::endl;
}

void FacereFormaCanonica(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	int nr=0,ok, indexColoana;
	for (int index = 0; index < std::min(nrLinii, nrColoane); index++)
	{
		indexColoana = index + nr;
		if (indexColoana >= nrColoane-1)
			break;
		if (matrice[index][indexColoana] != 0)
		{
			InmultireLinie(matrice, index, 1 / matrice[index][indexColoana], nrLinii, nrColoane);
			AfisareMatrice(matrice, nrLinii, nrColoane);
			for (int index2 = 0; index2 < nrLinii ; index2++)
				if(index2!=index)
				{
					if (matrice[index2][indexColoana] != 0)
					{
						AdunareLinii(matrice, index2, index, matrice[index2][indexColoana], nrLinii, nrColoane);
						AfisareMatrice(matrice, nrLinii, nrColoane);
					}
				}
		}
		else
		{
			ok = 0;
			for(int index2=index+1;index2<nrLinii;index2++)
				if (matrice[index2][indexColoana] != 0)
				{
					InterschimbareLinii(matrice,index,index2,nrLinii,nrColoane);
					AfisareMatrice(matrice, nrLinii, nrColoane);
					ok = 1;
					break;
				}
			if (ok == 0)
				nr++;
			index--;
		}
	}
}

int VerificareLinii(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	int nr0;
	for (int linie = nrLinii-1; linie >=0; linie--)
	{
		nr0 = 0;
		for (int coloana = 0; coloana < nrColoane - 1; coloana++)
		{
			if (matrice[linie][coloana] == 0)
				nr0++;
		}
		if ((nr0 == nrColoane - 1) && (matrice[linie][nrColoane - 1]!=0))
			return 0;
	}
	return 1;
}

void AflareDimensiuneI(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane,int& dimI)
{
	int nr1, nr0, index=0;
	for (int coloana = 0; coloana < nrColoane - 1; coloana++)
	{
		nr1 = 0;
		nr0 = 0;
		for (int linie = 0; linie < nrLinii; linie++)
		{
			if ((matrice[linie][coloana] == 1)&&(linie==index))
				nr1++;
			else if (matrice[linie][coloana] == 0)
				nr0++;
		}
		if ((nr1 == 1) && (nr0 == nrLinii-1))
		{
			index++;
			dimI++;
		}
	}
}

int  AflareFelSistem(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	int dimI = 0, ok;
	ok = VerificareLinii(matrice, nrLinii, nrColoane);
	if (ok == 0)
	{
	    std::cout << "Sistemul este imcompatibil" << std::endl;
		std::cout << "S = { nu are solutie }" << std::endl;
		return 0;
    }
	else
	{
		std::cout << "Sistemul este compatibil ";
		AflareDimensiuneI(matrice,nrLinii,nrColoane,dimI);
		if (dimI == nrColoane-1)
		{
			std::cout << "determinat" << std::endl;
			return 1;
		}
		else if(dimI<nrColoane)
		{
			if (nrColoane - dimI-1 == 1)
				std::cout << "simplu ";
			else if (nrColoane - dimI-1 == 2)
				std::cout << "dublu ";
			else if (nrColoane - dimI-1 == 3)
				std::cout << "triplu ";
			else if (nrColoane - dimI-1 == 4)
				std::cout << "cvadruplu ";
			else if (nrColoane - dimI-1 == 5)
				std::cout << "cvintuplu ";
			else if (nrColoane - dimI-1 == 6)
				std::cout << "sextuplu ";
			else if (nrColoane - dimI-1 == 7)
				std::cout << "septuplu ";
			else if (nrColoane - dimI-1 == 8)
				std::cout << "octuplu ";
			else
				std::cout << " mai mult de octuplu ";
			std::cout << "nedeterminat" << std::endl;
		}
		return 2;
	}
}

void AfisareSolutiiCaz1(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	std::cout << "S = { ";
	for (int linie = 0; linie < nrLinii - 1; linie++)
		std::cout << matrice[linie][nrColoane - 1] << " , ";
	std::cout << matrice[nrLinii - 1][nrColoane - 1] << " }" << std::endl;
}

void AfisareSolutiiCaz2(std::vector<std::vector<double>>& matrice, int& nrLinii, int& nrColoane)
{
	std::cout << "S = { ";
	int index = 0, ok, nr1, nr0, pozitie = 0;
	for (int coloana = 0; coloana < nrColoane - 1; coloana++)
	{
		nr1 = 0;
		nr0 = 0;
		ok = 0;
		for (int linie = 0; linie < nrLinii; linie++)
		{
			if ((matrice[linie][coloana] == 1) && (linie == index))
				nr1++;
			else if (matrice[linie][coloana] == 0)
				nr0++;
		}
		if ((nr1 == 1) && (nr0 == nrLinii - 1))
		{
			ok = 1;
		}
		if (ok == 0)
			std::cout <<char('a' + coloana);
		else
		{
			std::cout << matrice[index][nrColoane - 1];
			for (int index1 = 0; index1 < nrColoane - 1; index1++)
			{
				if ((matrice[index][index1] != 0)&&(index1!=pozitie))
				{
					if (matrice[index][index1] < 0)
						std::cout << "+";
					std::cout << -1 * matrice[index][index1] << char('a' + index1);
				}
			}
		}
		if (coloana!=nrColoane-2)
			std::cout << " , ";
		if ((nr1 == 1) && (nr0 == nrLinii - 1))
		{
			index++;
		}
		pozitie++;
	}
	std::cout << " }" << std::endl;
}

int main()
{
	std::vector<std::vector<double>> matrice;
	int nrLinii=0, nrColoane=0,ok;
	if (CitireMatrice(matrice,nrLinii,nrColoane))
	{
		FacereFormaCanonica(matrice,nrLinii,nrColoane);
		ok = AflareFelSistem(matrice, nrLinii, nrColoane);
		if (ok == 1)
			AfisareSolutiiCaz1(matrice, nrLinii, nrColoane);
		else if (ok == 2)
			AfisareSolutiiCaz2(matrice, nrLinii, nrColoane);
	}
	return 0;
}