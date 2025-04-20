#include <iostream>
#include <mpi.h>
#include <vector>

int main(int argc, char** argv) 
{
	/*
	  Scenariul 3: Comunicare distribuita
	  Procesul cu rank-ul 0 contine un vector numeric
	  Sa se imparta datele in 
	*/

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	std::vector<int> send_buffer;
	constexpr int  element_per_proc = 1;
	if (rank == 0)
	{
		send_buffer = { 7, 1, 2, 3, 5, 6, 7, 8 };
	}

	std::vector<int> recv_buffer(element_per_proc);

	MPI_Scatter(recv_buffer.data(), element_per_proc,
		MPI_INT, recv_buffer.data(), element_per_proc, MPI_INT,
		0, MPI_COMM_WORLD);

	std::cout << "Procesul cu rank-ul " << rank << " contine: ";
	for(int index = 0; index < recv_buffer.size(); index++)
	{
		std::cout << recv_buffer[index] << " ";
	}

	MPI_Finalize();
	return 0;
}