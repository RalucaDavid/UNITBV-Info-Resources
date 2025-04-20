#include <iostream>
#include <mpi.h>
#include <vector>

int main(int argc, char** argv) 
{
	/*
	  Scenariul 5: Comunicare circulara/inel (ring communication)
	  Procesul 0 -> 1, 1 -> 2,.... n->0
	*/

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int left, right;
	int ibuff, obuff, sum=0;
	int tag = 1;

	right = rank + 1;
	if (right == size)
		right = 0;
	left = rank - 1;
	if (left == -1)
		left = size - 1;
	obuff = rank;

	for (int index = 0; index < size; index++)
	{
		// trimitem catre dreapta
		MPI_Send(&obuff, 1, MPI_INT, right, tag, MPI_COMM_WORLD);
		// primesc de la stanga
		MPI_Recv(&ibuff, 1, MPI_INT, left, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		//actualizare suma
		sum = sum + ibuff;
		obuff = ibuff;
	}

	std::cout << "Procesul cu rank-ul " << rank << " are suma " << sum << "\n";

	MPI_Finalize();
	return 0;
}