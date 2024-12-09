#include <iostream>

int CautareBinara(int*& vector, int indiceInceput, int indiceFinal, const int& element)
{
	if (indiceInceput <= indiceFinal)
	{
		int indiceMijloc = (indiceInceput + indiceFinal) / 2;
		if (vector[indiceMijloc] == element)
			return indiceMijloc;
		if (vector[indiceMijloc] > element)
			return CautareBinara(vector, indiceInceput, indiceMijloc - 1, element);
		if (vector[indiceMijloc] < element)
			return CautareBinara(vector, indiceMijloc + 1, indiceFinal, element);
	}
	return -1;
}

int main()
{

	return 0;
}