#include <iostream>
#include <mpi.h>

bool estePrim(long n)
{
	if (n < 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0) return false;
	for (int divizor = 2; divizor <= std::sqrt(n); divizor++)
	{
		if (n % divizor == 0)
			return false;
	}
	return true;
}


int main(int argc, char** argv) 
{
	int rank, size;

	// Structura unui program paralel - MPI
	// FROM HERE
	// Functie de initializare paralela
	MPI_Init(&argc, &argv);

	// Cum populam rank-ul (id-ul/nr procesului)
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	// Cum populam size (cate procese sunt)
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	//std::cout << "Test MPI rank = " <<rank<<" size = "<<size<< std::endl;

	//std::cout.flush();

 //   // bariera (stop) artificial pt sincronizare
 //   // Toate procesele o sa treaca de bariera doar in momentul in care toate procesele au ajuns la ea
	//MPI_Barrier(MPI_COMM_WORLD);  // pt sincronizare


	//if (rank == 0)
	//{
	//	std::cout << "\nToate procesele au ajuns la bariera\n\n";
	//	std::cout.flush();
	//}


	/*
	  Se considera un numar n foarte mare
	  Se considera intervalul [1, n]
	  Sa se contorizeze eficient care nr. prime sunt in range
	  (Sa se contorizeze timpul de executie)
	*/

	int n = 1'000'000; 
	int count = 0;

	int start = rank * n / size + 1;
	int end = (rank + 1) * n / size;
	double time = MPI_Wtime();
	for (int i = start; i <= end; i++)
		if (estePrim(i))
			count++;
	time = MPI_Wtime() - time;
	std::cout << "Procesul cu rank-ul " << rank << " a gasit " << count << " nr prime " << " in " << time << " secunde" << std::endl;

	// Functie de finalizare/stop pt. procesul paralel
	MPI_Finalize();
	// TO HERE 


	/*
	  Speedup = Tserial/Tparalel
	*/

	return 0;
}