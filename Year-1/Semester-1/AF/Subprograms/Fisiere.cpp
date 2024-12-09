#include <iostream>

// Veficare existenta fisier

if (!Fin.is_open())
{
	std::cout << "Fisierul nu exista sau nu a putut fi deschis!"<<std::endl;
	return 0;
}

// Verificare sfarsit fisier

if (Fin.eof())
{
	std::cout << "Am ajuns la finalul fisierului";
	return 0;
}

int main()
{

	return 0;
}