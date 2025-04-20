#include <iostream>
#include <mpi.h>
#include <vector>

int main(int argc, char** argv) 
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	std::vector<int> input_array;
	int n = 10'000'000;

	if (rank == 0)
	{
		for (int i = 0; i < n; i++)
			input_array.push_back(i);
	}

	std::vector<int> scattered_array(n/size);
	MPI_Scatter(input_array.data(), n/size, MPI_INT,
		scattered_array.data(), n/size, MPI_INT, 0, MPI_COMM_WORLD);

	//operatii predefinite
	long long sum = 0, final_sum = 0;
	int min = INT_MAX, final_min = INT_MAX;
	int max = INT_MIN, final_max = INT_MIN;

	for (int i = 0; i < n / size; i++)
	{
		sum += scattered_array[i];
		min = std::min(min, scattered_array[i]);
		max = std::max(max, scattered_array[i]);
	}
	std::cout << "Procesul cu rank-ul " << rank << " a calculat suma " << sum<<"\n";
	std::cout << "Procesul cu rank-ul " << rank << " a calculat min " << min << "\n";
	std::cout << "Procesul cu rank-ul " << rank << " a calculat max " << max << "\n";
	std::cout.flush();

	MPI_Reduce(&sum, &final_sum,1,MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&min, &final_min, 1, MPI_LONG_LONG, MPI_MIN, 0, MPI_COMM_WORLD);
	MPI_Reduce(&max, &final_max, 1, MPI_LONG_LONG, MPI_MAX, 0, MPI_COMM_WORLD);

	if (rank == 0)
	{
		std::cout << "Suma totala este " << final_sum << "\n";
		std::cout << "Minumul totala este " << final_min << "\n";
		std::cout << "MAximul totala este " << final_max << "\n";
	}

	MPI_Finalize();
	return 0;
}