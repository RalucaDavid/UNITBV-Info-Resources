#include <iostream>
#include <string>
#include <iterator>

bool CitireInformatiileProblemei(int&n,int&m,int&k)
{
	std::cout << "Introduceti lungimea lui p: ";
	std::cin >> n;
	std::cout << "Introduceti lungimea lui q: ";
	std::cin >> m;
	std::cout << "Introduceti exponentul: ";
	std::cin >> k;
	std::cout << std::endl;
	if ((k < 0) || (n < 0) || (m < 0))
	{
		std::cout << "Una sau mai multe variabile nu sunt valide!" << std::endl;
		return false;
	}
	return true;
}

void ExempluSiCeSaAratamInitial()
{
	std::cout << "Pentru n=0 => pq0=r0p => p=p => Adevarat"<<std::endl;
	std::cout << "Pentru n=1 => pq=rp ? "<<std::endl;
	std::cout << std::endl;
}

void PunereIndicii(std::string& cuvant,int index)
{
	while (index> 0)
	{
		cuvant.insert(cuvant.begin() + cuvant.find_last_of('a') + 1, 48 + index % 10);
		index = index / 10;
	}
}

void AflareR(const int& n, const int& m, int& lungimeR, std::string& r, const int& k)
{
	std::cout << "l(pq" << k << ") = l(r" << k << "p) => l(p)+" << k << "l(q) = " << k << "l(r)+l(p) => l(q) = l(r)" << std::endl;
	lungimeR = (n + k * m - n) / k; // <= l(p)+k*l(q) = k*l(r)+l(p)
	std::cout << "Lungimea lui r este: " << lungimeR<< std::endl;
	for (int index = 1; index <= lungimeR; index++)
	{
		r.push_back('a');
		PunereIndicii(r, index);
	}
	std::cout << "Deci r = " << r << std::endl;
	std::cout << std::endl;
}

void Concatenarea(const int& n,int& lungimeR,int& k, int& c)
{
	c = 0;
	while (lungimeR*(k*(c+1)) < n)
	{
		std::cout << "l(r" << k * (c + 1) << ") = " << lungimeR * (k * (c + 1)) << " < " << n << std::endl;
		std::cout << "Concatenam cu q" << k << std::endl;
		c++;
	}
	std::cout << "l(r" << k * (c + 1) << ") = " << lungimeR * (k * (c + 1)) << " > " << n << std::endl;
	std::cout << "Numarul de concatenari pentru gasirea lui p este: " << c << std::endl;
	std::cout << "p este prefixul de lungimea " << n << " a lui r la puterea " << (c + 1) * k<<std::endl;
	std::cout << std::endl;
}

void AflareP(const int& n,std::string& p,const int& lungimeR)
{
	std::cout << n << " = " << lungimeR<<"*"<<(n / lungimeR) << "+" << n % lungimeR << std::endl;
	p.push_back('r');
	int aux = n / lungimeR;
	while (aux > 0)
	{
		p.insert(p.begin() + p.find_last_of('r') + 1, 48 + aux % 10);
		aux = aux / 10;
	}
	for (int index = 1; index <= n % lungimeR; index++)
	{
		p.push_back('a');
	    PunereIndicii(p, index);
	}
	std::cout << "Deci p = "<<p<<std::endl;
	std::cout << std::endl;
}

void AflareQ(std::string& q,std::string& p,std::string& r,const int& k,const int& lungimeR,const int&n)
{
	std::cout << "pq" << k << " = r" << k << "p" << std::endl;
	std::cout << p << "q" << k << " = r" << k << p << std::endl;
	std::string aux, aux1;
	for (int index = n % lungimeR + 1; index <= lungimeR; index++)
	{
		aux.push_back('a');
		PunereIndicii(aux, index);
	}
	for (int index = 1; index <= n % lungimeR; index++)
	{
		aux1.push_back('a');
		PunereIndicii(aux1, index);
	}
	std::cout << p << "q" << k << " = " << p<<aux<<"r"<<k-1<<aux1<<std::endl;
	std::cout << "q" << k << " = " << aux << "(" << r << ")" << k - 1 << aux1 << std::endl;
	std::cout << "q" << k << " = " << "(" << aux << aux1 << ")" << k<<std::endl;
	q = aux + aux1;
	std::cout << "Deci q = " << q << std::endl;
	std::cout << std::endl;
}

void VerificareInitial(std::string p, std::string q, std::string r,const int& lungimeR,const int&n)
{
	std::cout << "pq = " << p << q << " = r" << n / lungimeR + 1;
	for (int index = 1; index <= n % lungimeR; index++)
		std::cout << "a" << index;
	std::cout << std::endl;
	std::cout << "rp = " << "r" << p << " = r" << n / lungimeR + 1;
	for (int index = 1; index <= n % lungimeR; index++)
		std::cout << "a" << index;
	std::cout << std::endl;
	std::cout << "=> pq=rp" << std::endl;
	std::cout << std::endl;
}

void DemonstratieInductieMatematica()
{
	std::cout << "Aratam prin inductie P(n): pqn = rnp, oricare ar fi n apartine lui N*" << std::endl;
	std::cout << "Pasul 1:" << std::endl;
	std::cout << "n = 1     pq=rp  => Adevarat - demonstrat mai sus" << std::endl;
	std::cout << "Pasul 2:" << std::endl;
	std::cout << "P(k) -> P(k+1)" << std::endl;
	std::cout << "Presupunem pqk=rkp" << std::endl;
	std::cout << "Demonstram pq(k+1)=r(k+1)p" << std::endl;
	std::cout << "Stim pqk = rkp /*q" << std::endl;
	std::cout << "pq(k+1) = rkpq => pq(k+1) = r(k+1)p => Adevarat" << std::endl;
	std::cout << "=> pqn=rnp" << std::endl;
}

int main()
{
	int n, m, k; // n = l(p), m = l(q), k = exponentul
	int c; // c = numarul de concatenari pentru gasirea lui p
	int lungimeR; // lungimeR = l(r)
	std::string r,p,q;
	if (CitireInformatiileProblemei(n, m, k))
	{
		ExempluSiCeSaAratamInitial();
		AflareR(n, m, lungimeR, r, k);
		Concatenarea(n, lungimeR, k, c);
		AflareP(n, p, lungimeR);
		AflareQ(q, p, r, k, lungimeR, n);
		VerificareInitial(p, q, r, lungimeR, n);
		DemonstratieInductieMatematica();
		r.clear();
		p.clear();
		q.clear();
	}
	return 0;
}