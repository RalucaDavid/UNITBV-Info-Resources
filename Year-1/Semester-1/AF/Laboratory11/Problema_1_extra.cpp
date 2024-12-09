#include <iostream>
#include <fstream>
#include <vector>
#include <array>

bool CitireDate(std::vector<std::vector<int>>& hartaVecini, int& nrTari)
{
   std::ifstream fin("FisierProblema1.intrare");
   fin >> nrTari;
   if (nrTari < 0)
   {
	   std::cout << "Numarul de Tari este invalid!" << std::endl;
	   fin.close();
	   return false;
   }
   for (int linie = 0; linie < nrTari; linie++)
   {
	   std::vector<int> vectorLinie;
	   for (int coloana = 0; coloana < nrTari; coloana++)
	   {
		   vectorLinie.push_back(0);
	   }
	   hartaVecini.push_back(vectorLinie);
   }
   int tara, vecin;
   while (!fin.eof())
   {
	   fin >> tara >> vecin;
	   hartaVecini[tara-1][vecin-1] = -1;
	   hartaVecini[vecin-1][tara-1] = -1;
   }
   fin.close();
   return true;
}

void Colorare(std::vector<std::vector<int>>& hartaVecini,const int& nrTari,const std::array<int, 4>& culori)
{
	int indexCuloare = 0;
	for (int linie = 0; linie < nrTari; linie++)
	{
		bool ok = true;
		for(int coloana=0;coloana<nrTari;coloana++)
			if (hartaVecini[linie][coloana] == -1)
			{
				if (hartaVecini[coloana][coloana] == culori[indexCuloare])
				{
					coloana = nrTari;
					ok = false;
				}
		    }
		if (ok == true)
		{
			hartaVecini[linie][linie] = culori[indexCuloare];
			indexCuloare = 0;
		}
		else
		{
			linie--;
			indexCuloare++;
		}
	}
}

void Afisare(const std::vector<std::vector<int>>& hartaVecini, const int& nrTari)
{
	for (int index = 0; index < nrTari; index++)
		std::cout << "Tara " << index + 1 << " are culoare " << hartaVecini[index][index] << std::endl;
}
int main()
{
	std::vector<std::vector<int>> hartaVecini = {};
	int nrTari=0;
	std::array<int, 4> culori = {1,2,3,4};
	if (CitireDate(hartaVecini, nrTari))
	{
		Colorare(hartaVecini, nrTari, culori);
		Afisare(hartaVecini, nrTari);
	}
	return 0;
}
