#include<iostream>
int sumaCifre(int b)
{
	if (b != 0)
          return b % 10 + sumaCifre(b / 10);
}
void perechi(int n)
{
	for (int i = 1; i <= n; i++)
	 for (int j = i + 1; j <= n; j++)
	   if (sumaCifre(i) == sumaCifre(j))
	    std::cout << i << ' ' << j<<std::endl;
}
int main()
{
  int n;
  std::cin>>n;
  perechi(n);
  return 0;
}