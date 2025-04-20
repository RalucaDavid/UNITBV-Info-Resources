#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) 
{
	/*
	  Scenariul 1: Comunicare de baza (P2P - pair to pair)
	  Procesul cu rank-ul 0 trimite un mesaj
	  (numar/string) catre procesul cu rank 1
	*/

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		const int number_message = 20;
		/*const char* b = a.c_str();*/
		MPI_Send(&number_message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		std::cout << "Procesul cu rank-ul " << rank << " trimite mesajul " << number_message<<"\n";

		const char* string_message = "Hello";
		MPI_Send(&string_message, strlen(string_message) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
		std::cout << "Procesul cu rank-ul " << rank << " trimite mesajul " << string_message << "\n";
	}
	else if(rank == 1)
	{
		int number_message;
		MPI_Recv(&number_message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		std::cout << "Procesul cu rank-ul " << rank << " primeste mesajul " << number_message << "\n";

		MPI_Status status;
		MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
		int size;
		MPI_Get_count(&status, MPI_CHAR, &size);
		std::cout << "Dimensiunea: " << size << "\n";


		char* string_message = new char[size];
		MPI_Recv(&string_message, size, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		std::cout << "Procesul cu rank-ul " << rank << " primeste mesajul " << string_message << "\n";

	}

	MPI_Finalize();
	return 0;
}