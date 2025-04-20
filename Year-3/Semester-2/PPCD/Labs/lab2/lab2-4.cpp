#include <iostream>
#include <mpi.h>
#include <vector>

int main(int argc, char** argv) 
{
	/*
	  Scenariul 4: Comunicare point to point (ping pong)
	  Procesul 0 -> 1 si 1 -> 0
	*/

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size!=2)
	{
		std::cerr << "Avem nevoie de 2 procese MPI";
		MPI_Finalize();
		return 1;
	}

	int in_msg, out_msg;
	int tag = 1;
	int destinatie = (rank == 0) ? 1 : 0;
	int sursa = destinatie; // nu e neaparat 
	
	out_msg = (rank == 0) ? 1234 : 5678;

	std::cout << "Procesul cu rank-ul " << rank << " trimite " << out_msg << " catre " << destinatie<<"\n";

	MPI_Sendrecv(&out_msg, 1, MPI_INT, destinatie, tag, 
		&in_msg, 1, MPI_INT, sursa, tag,
		MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	std::cout << "Procesul cu rank-ul " << rank << " a primit " << in_msg<<"\n";

	MPI_Finalize();
	return 0;
}