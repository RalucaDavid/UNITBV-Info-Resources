#include <iostream>
#include <vector>

template <typename T>
bool CitireDateProblema(T& a, T& m, T& n)
{
	std::cout << "Introduceti deimpartitul:";
	std::cin >> a;
	std::cout << "Introduceti exponentul deimpartitului:";
	std::cin >> m;
	std::cout << "Introduceti impartitorul:";
	std::cin >> n;
	if ((a < 0) || (n < 1)||(m<0))
	{
		std::cout << "Valorile sunt invalide!" << std::endl;
		return false;
	}
	return true;
}

template <typename T>
bool VerificarePrime(T a, T n)
{
	while (n != 0)
	{
		T r=a%n;
		a = n;
		n = r;
	}
	if (a == 1)
		return true;
	return false;
}

template <typename T>
void AfisareCerinta(const T& a,const T& m,const T& n)
{
	std::cout << "Sa se determine:"<<std::endl;
	std::cout << a << "^" << m << ":" << n << "=?"<<std::endl;
	std::cout << std::endl;
}

struct factori
{
	int putere, nr,calcul; // p-puterea, nr-factor prim
};

template <typename T>
void DescompunereFactoriPrimi(std::vector<factori>& factoriPrimi,T n)
{
	T d = 2,p;
	factori element;
	if (n == 1)
	{
		element.nr = 1;
		element.putere = 1;
		factoriPrimi.push_back(element);
	}
	while (n > 1)
	{
		p = 0;
		while (n % d == 0)
		{
			p++;
			n = n / d;
		}
		if (p)
		{
			element.nr = d;
			element.putere = p;
			factoriPrimi.push_back(element);
		}
		d++;
		if ((n > 1) && (d * d > n))
			d = n;
	}
}

template <typename T>
T FolosireaTeoremeiEuler(std::vector<factori>& factoriPrimi,T a, T m, T n)
{
	T total = 1;
	std::cout << "T. Euler: (a,n)=1 => a^f(n)=1 in Zn" << std::endl; // f-fi grecesc
	std::cout << "(" << a << "," << n << ")=1 => " << a << "^f(" << n << ")=1 in Z" << n << std::endl;
	std::cout << "f(" << n << ")=f(";
	for (T index = 0; index < factoriPrimi.size(); index++)
	{
		std::cout << factoriPrimi[index].nr << "^" << factoriPrimi[index].putere;
		if (index != factoriPrimi.size() - 1)
			std::cout << "*";
		else
			std::cout << ")" << std::endl;
	}
	std::cout << "=";
	for (T index = 0; index < factoriPrimi.size(); index++)
	{
		std::cout <<"f("<<factoriPrimi[index].nr << "^" << factoriPrimi[index].putere<<")";
		if (index != factoriPrimi.size() - 1)
			std::cout << "*";
		else
			std::cout<< std::endl;
	}
	std::cout << "=";
	for (T index = 0; index < factoriPrimi.size(); index++)
	{
		std::cout << "(" << factoriPrimi[index].nr << "^" << factoriPrimi[index].putere << "-" << factoriPrimi[index].nr << "^" << factoriPrimi[index].putere - 1 << ")";
		factoriPrimi[index].calcul = pow(factoriPrimi[index].nr,factoriPrimi[index].putere) - pow(factoriPrimi[index].nr, factoriPrimi[index].putere-1);
	}
	std::cout << std::endl << "=";
	for (T index = 0; index < factoriPrimi.size(); index++)
	{
		std::cout << factoriPrimi[index].calcul;
		total = total * factoriPrimi[index].calcul;
		if (index != factoriPrimi.size() - 1)
			std::cout << "*";
		else
			std::cout << std::endl;
	}
	std::cout << "=" << total;
	std::cout << std::endl;
	std::cout << "=>" << a << "^" << total << "=1" << " in Z" << n << std::endl;
	std::cout << std::endl;
	return total;
}

template<typename T>
T RestInClasa(T a, T m, T n)
{
	int aux = 1;
	while (m > 0)
	{
		aux = aux * a;
		if (aux / n != 0)
			aux = aux % n;
		m--;
	}
	return aux;
}

template <typename T>
T AflareRest(T a, T m, T n, T puterea)
{
	std::cout << "=>" << a << "^" << m << "=" << "(" << a << "^" << puterea << ")^(" << m / puterea<<"+"<< m % puterea << ")" << std::endl;
	std::cout << "=(" << a << "^" << puterea << ")^" << m / puterea << "*" << a << "^" << m % puterea << std::endl;
	T rest = RestInClasa(a, m % puterea, n);
	std::cout << "=> restul=" << rest << " in Z" << n << std::endl;
	std::cout<<std::endl;
	return rest;
}

template <typename T>
void Cazuri(T a,T m,T n,bool ok)
{
	auto aux = n, aux1 = m, k = 1;
	std::vector<factori> factoriPrimi;
	DescompunereFactoriPrimi(factoriPrimi, n);
	auto puterea = FolosireaTeoremeiEuler(factoriPrimi,a, m, n);
	auto rest = AflareRest(a, m, n, puterea);
}

int main()
{
	auto a=0, m=0,n=0;
	if (CitireDateProblema(a, m, n))
	{
		AfisareCerinta(a, m, n);
		bool ok = VerificarePrime(a, n);
		Cazuri(a, m, n, ok);
	}
	return 0;
}