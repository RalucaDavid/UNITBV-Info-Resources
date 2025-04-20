#include <iostream>
#include <mpi.h>
#include <vector>
#include <string>
#include <fstream>

std::string read_text_from_file(const std::string& filename)
{
	std::ifstream fisier(filename, std::ios::ate);
	if (!fisier)
	{
		std::cout << "Fisierul nu exista!\n";
		return "";
	}
	std::streamsize size = fisier.tellg();
	std::cout << "Dimensiune este: " << size << "\n";
	
	std::string data(size, '\0');
	fisier.seekg(0, std::ios::beg);

	fisier.read(&data[0], size);

	return data;
}

int main(int argc, char** argv) 
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	std::string text;
	std::string pattern = "ATCG";
	double time;
	if (rank == 0)
	{
		time = MPI_Wtime();
		text = read_text_from_file("nucleotides_100000000.txt");
		time = MPI_Wtime() - time;
		std::cout << "Citirea s-a finalizat in " << time << "\n";
		std::cout.flush();
	}
	int text_length = text.size();


	MPI_Finalize();
	return 0;
}