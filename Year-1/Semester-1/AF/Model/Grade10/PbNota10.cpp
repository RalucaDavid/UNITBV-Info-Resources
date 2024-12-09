#include <iostream>
#include <fstream>
#include <stdlib.h>

void AlocareDinamica(float**& matrice, int& nrLinii, int& nrColoane)
{
	matrice = new float* [nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
	{
		matrice[linie] = new float[nrColoane];
	}
	std::cout << "Alocarea s-a facut cu succes!" << std::endl;
}

int CitireMatrice(float**& matrice, int& nrLinii, int& nrColoane)
{
	std::ifstream Fin("FisierIntrare.in");
	if (!Fin.is_open())
	{
		std::cout << "Fisierul nu exista sau nu a putut fi deschis!" << std::endl;
		return 0;
	}
	Fin >> nrLinii >> nrColoane;
	if ((nrLinii < 0) || (nrColoane < 0))
	{
		std::cout << "Unul dintre parametri este invalid!" << std::endl;
		return 0;
	}
	AlocareDinamica(matrice, nrLinii, nrColoane);
	for (int linie = 0; linie < nrLinii; linie++)
		for (int coloana = 0; coloana < nrColoane; coloana++)
		{
			if (Fin.eof())
			{
				std::cout << "Am ajuns la finalul fisierului";
				return 0;
			}
			Fin >> matrice[linie][coloana];
		}
	std::cout << "Citirea s-a facut cu succes!" << std::endl;
	Fin.close();
	return 1;
}

void AfisareMatrice(float**& matrice, const int& nrLinii, const int& nrColoane)
{
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane; coloana++)
			std::cout << matrice[linie][coloana] << ' ';
		std::cout << std::endl;
	}
}

void DealocareDinamica(float**& matrice, int& nrLinii)
{
	for (int linie = 0; linie < nrLinii; linie++)
		delete[] matrice[linie];
	delete[] matrice;
	std::cout << "Dealocarea s-a facut cu succes!" << std::endl;
}

void CMProfitabilaCripto(float**& matrice,const int&nrLinii,const int&nrColoane)
{
	float maxim=(matrice[0][nrColoane-1]-matrice[0][0])/matrice[0][0]*100;
	int nrCripto = 0;
	for(int linie=1;linie<nrLinii;linie++)
		if (maxim < (matrice[linie][nrColoane - 1] - matrice[linie][0]) / matrice[linie][0] * 100)
		{
			maxim = (matrice[linie][nrColoane - 1] - matrice[linie][0]) / matrice[linie][0] * 100;
			nrCripto = linie;
	    }
	std::cout << "Criptomoneda " << nrCripto << " cu "<< maxim << "% profit." << std::endl;
}

void IntervaleCMMPierdere(float**& matrice, const int& nrLinii, const int& nrColoane)
{
	
	for (int linie = 0; linie < nrLinii; linie++)
	{
		float pierdere = matrice[linie][0] - matrice[linie][1];
		int zi1 = 0, zi2 = 1;
		for (int coloana = 1; coloana < nrColoane - 1; coloana++)
			if (pierdere < matrice[linie][coloana] - matrice[linie][coloana + 1])
			{
				pierdere = matrice[linie][coloana] - matrice[linie][coloana + 1];
				zi1 = coloana;
				zi2 = coloana + 1;
			}
		std::cout << "De la ziua cu indexul " << zi1 << " la ziua cu indexul " << zi2 << " am fi avut o pierdere de " << pierdere << std::endl;
	}
}

struct Zile
{
	float ZiCresc, ZiDescr, Diferenta;
};

void Interschimbare(float& element1, float& element2)
{
	float auxiliar = element1;
	element1 = element2;
	element2 = auxiliar;
}

void InterschimbareLinii(float**& matrice, int linie, int linie1 , int nrColoane)
{
	for (int coloana = 0; coloana < nrColoane; coloana++)
		Interschimbare(matrice[linie][coloana], matrice[linie1][coloana]);
}

int Partitie(float**& matrice, int indexStart, int indexFinal,int nrColoane,Zile*& Frecventa)
{
	int pivot = Frecventa[indexFinal].Diferenta;
	int index = indexStart;
	for (int contor = indexStart; contor <= indexFinal; contor++)
	{
		if (Frecventa[contor].Diferenta <= pivot)
		{
			InterschimbareLinii(matrice, index, contor, nrColoane);
			Interschimbare(Frecventa[indexFinal].Diferenta, Frecventa[contor].Diferenta);
			index++;
		}
	}
	return index - 1;
}

void QuickSort(float**& matrice, int indexStart, int indexFinal,int nrColoane,Zile*& Frecventa)
{
	int partitie;
	if (indexStart < indexFinal)
	{
		partitie = Partitie(matrice, indexStart, indexFinal,nrColoane,Frecventa);
		QuickSort(matrice, indexStart, partitie - 1,nrColoane,Frecventa);
		QuickSort(matrice, partitie + 1, indexFinal,nrColoane,Frecventa);
	}
}

void OrdonareCripto(float**& matrice, const int& nrLinii, const int& nrColoane)
{
	Zile* Frecventa = new Zile[nrLinii];
	for (int index = 0; index < nrLinii; index++)
	{
		Frecventa[index].ZiCresc = 0;
		Frecventa[index].ZiDescr = 0;
	}
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane - 1; coloana++)
			if (matrice[linie][coloana] <= matrice[linie][coloana + 1])
				Frecventa[linie].ZiCresc++;
			else if(matrice[linie][coloana] >matrice[linie][coloana + 1])
				Frecventa[linie].ZiDescr++;
		Frecventa[linie].Diferenta = Frecventa[linie].ZiCresc - Frecventa[linie].ZiDescr;
	}
	QuickSort(matrice, 0, nrLinii - 1,nrColoane,Frecventa);
	delete[] Frecventa;
}

struct Fluct
{
	float minim, maxim, fluctuatie;
};

void AfisareUrm3Zile(const int& nrCripto, Fluct*& vector)
{
	srand(time(NULL));
	std::ofstream Fout("FisierIesire.out");
	for (int index = 0; index < nrCripto; index++)
	{
		int zile = 3;
		while (zile > 0)
		{
			int PretNou = vector[index].minim + (std::rand() % (int(vector[index].maxim - vector[index].minim + 1)));
			Fout << PretNou << " ";
			if (PretNou < vector[index].minim)
				vector[index].minim = PretNou;
			if (PretNou > vector[index].maxim)
				vector[index].maxim = PretNou;
			vector[index].fluctuatie= vector[index].maxim - vector[index].minim;
			zile--;
		}
		Fout << std::endl;
	}
	Fout.close();
}

void AflareFluctuatie(float**& matrice, const int& nrLinii, const int& nrColoane)
{
	Fluct* vector = new Fluct[nrLinii];
	for (int linie = 0; linie < nrLinii; linie++)
	{
		vector[linie].minim = matrice[linie][0];
		vector[linie].maxim = matrice[linie][0];
		for (int coloana = 1; coloana < nrColoane; coloana++)
		{
			if (vector[linie].minim < matrice[linie][coloana])
				vector[linie].minim = matrice[linie][coloana];
			if (vector[linie].maxim > matrice[linie][coloana])
				vector[linie].maxim = matrice[linie][coloana];
		}
		vector[linie].fluctuatie = vector[linie].maxim - vector[linie].minim;
	}
	AfisareUrm3Zile(nrLinii, vector);
	delete[] vector;
}

int main()
{
	int n = 0, m = 0;
	float** matrice = {};
	if (CitireMatrice(matrice, n, m) == 1);
	{

		CMProfitabilaCripto(matrice, n, m);
		IntervaleCMMPierdere(matrice, n, m);
		AflareFluctuatie(matrice, n, m);
		OrdonareCripto(matrice, n, m);
		AfisareMatrice(matrice, n, m);
		DealocareDinamica(matrice, n);
	}
	return 0;
}