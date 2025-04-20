#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) 
{
	/*
	  Scenariul 2: Comunicare Broadcast
	  Procesul cu rank-ul 0 trimite un mesaj
	  (numar/string) catre procesul cu rank 1
	*/

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int broadcast_message = 77; // valoare initiala
	if (rank == 0)
		broadcast_message = 42; // valoare broadcast
	// Functie broadcast
	MPI_Bcast(&broadcast_message, 1, MPI_INT, 0, MPI_COMM_WORLD);
	std::cout << "procesul cu rank-ul " << rank << " primeste mesajul " << broadcast_message;


	MPI_Finalize();
	return 0;
}