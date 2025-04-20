#include <iostream>
#include <mpi.h>
#include <vector>
#include <time.h>
#include <stdlib.h>

/* 
	  Jocul de "piatra, foarfeca, hartie"
	  0 1 2
*/

int generareAlegere()
{
	return rand() % 3;
}

int determinareCastigator(int alegere1, int alegere2)
{
	if(alegere1 == alegere2)
		return 0; // egalitate
	if((alegere1==0 && alegere2 == 1) ||
		(alegere1 == 1 && alegere2 == 2) ||
		(alegere1 == 2 && alegere2 == 0))
			return 1; // jucator 1
	return 2; // jucator 2
}

int main(int argc, char** argv) 
{

	int rank, size;
	int tag = 1;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	srand(time(NULL)+rank); // alegerea seed-ului pt random
	int alegere = generareAlegere();

	if (rank == 0)
	{
		int alegerea_celuilalt;
		MPI_Send(&alegere, 1, MPI_INT, 1, tag, MPI_COMM_WORLD); // nu e neaparat
		MPI_Recv(&alegerea_celuilalt, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		std::cout << "Jucatorul 1 a ales " << alegere<<"\n";
		std::cout << "Jucatorul 2 a ales " << alegerea_celuilalt<<"\n";
		int castigator = determinareCastigator(alegere, alegerea_celuilalt);
		if (castigator == 0)
			std::cout << "Egalitate!\n";
		else
			std::cout << "A castigat jucatorul " << castigator;
	}
	else if (rank == 1)
	{
		int alegerea_celuilalt;
		MPI_Send(&alegere, 1, MPI_INT, 0, tag, MPI_COMM_WORLD); // nu e neaparat
		MPI_Recv(&alegerea_celuilalt, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}

	MPI_Finalize();
	return 0;
}