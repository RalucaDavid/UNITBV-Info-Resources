#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <limits>
#include <mpi.h>

enum class SortAlgorithm
{
    Invalid,
    DirectSort,
    BucketSort,
    OddEvenSort,
    RankingSort,
    ShellSort
};

std::string EnumToString(SortAlgorithm algorithm)
{
    switch (algorithm)
    {
        case SortAlgorithm::DirectSort:
            return "Direct Sort";
        case SortAlgorithm::BucketSort:
            return "Bucket Sort";
        case SortAlgorithm::OddEvenSort:
            return "Odd-Even Sort";
        case SortAlgorithm::RankingSort:
            return "Ranking Sort";
        case SortAlgorithm::ShellSort:
            return "Shell Sort";
        default:
            return "Invalid";
    }
}

std::vector<int> ReadDataFromFile(const std::string& filename)
{
    std::vector<int> data;

    std::ifstream fin(filename);
    if (!fin) 
    {
        std::cerr << "Unable to open file for reading." << std::endl;
        return data;
    }

    int num;
    while (fin >> num)
    {
        data.emplace_back(num);
    }

    fin.close();
    return data;
}

void MPI_Direct_Sort(std::vector<int>& data, const int rank, const int size)
{
    const int dataSize = static_cast<int>(data.size());
    std::vector<int> sendcounts(size, 0);
    std::vector<int> displs(size, 0);

    if (rank == 0)
    {
        int base = dataSize / size;
        int remainder = dataSize % size;
        int currentDispl = 0;
        for (int index = 0; index < size; index++) 
        {
            sendcounts[index] = base + (index < remainder ? 1 : 0);
            displs[index] = currentDispl;
            currentDispl += sendcounts[index];
        }
    }

    MPI_Bcast(sendcounts.data(), size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(displs.data(), size, MPI_INT, 0, MPI_COMM_WORLD);

    int localSize = sendcounts[rank];
    std::vector<int> localChunk(localSize);

    MPI_Scatterv(data.data(), sendcounts.data(), displs.data(), MPI_INT,
        localChunk.data(), localSize, MPI_INT,
        0, MPI_COMM_WORLD);

    for (int index = 0; index < localSize - 1; index++) 
    {
        int minIndex = index;
        for (int jndex = index + 1; jndex < localSize; jndex++) 
        {
            if (localChunk[jndex] < localChunk[minIndex])
                minIndex = jndex;
        }
        std::swap(localChunk[index], localChunk[minIndex]);
    }

    MPI_Gatherv(localChunk.data(), localSize, MPI_INT,
        data.data(), sendcounts.data(), displs.data(), MPI_INT,
        0, MPI_COMM_WORLD);

    if (rank == 0) 
    {
        std::vector<int> aSorted(dataSize);
        std::vector<int> posChunk(size, 0);

        for (int index = 0; index < dataSize; index++) 
        {
            int minValue = std::numeric_limits<int>::max();
            int chosenChunk = -1;

            for (int jndex = 0; jndex < size; ++jndex) 
            {
                if (posChunk[jndex] < sendcounts[jndex]) 
                {
                    int current_val = data[displs[jndex] + posChunk[jndex]];
                    if (current_val < minValue) 
                    {
                        minValue = current_val;
                        chosenChunk = jndex;
                    }
                }
            }

            if (chosenChunk != -1) 
            {
                aSorted[index] = minValue;
                posChunk[chosenChunk]++;
            }
        }

        data = std::move(aSorted);
    }

    MPI_Bcast(data.data(), dataSize, MPI_INT, 0, MPI_COMM_WORLD);
}

void MPI_Bucket_Sort(std::vector<int>& data, const int rank, const int size)
{
    int dataSize = data.size();
    MPI_Bcast(data.data(), dataSize, MPI_INT, 0, MPI_COMM_WORLD);

    int localMin = *std::min_element(data.begin(), data.end());
    int localMax = *std::max_element(data.begin(), data.end());

    int globalMin, globalMax;
    MPI_Allreduce(&localMin, &globalMin, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    MPI_Allreduce(&localMax, &globalMax, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

    int range = globalMax - globalMin + 1;
    int bucketSize = (range + size - 1) / size;
    int bucketStart = globalMin + rank * bucketSize;
    int bucketEnd = std::min(globalMin + (rank + 1) * bucketSize, globalMax + 1);

    std::vector<int> localBucket;
    for (int number : data) 
    {
        if (number >= bucketStart && number < bucketEnd) 
        {
            localBucket.push_back(number);
        }
    }

    std::sort(localBucket.begin(), localBucket.end());

    std::vector<int> recvCounts(size);
    int local_size = localBucket.size();
    MPI_Gather(&local_size, 1, MPI_INT, recvCounts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    std::vector<int> displs(size, 0);
    if (rank == 0) 
    {
        for (int index = 1; index < size; index++) 
        {
            displs[index] = displs[index - 1] + recvCounts[index - 1];
        }
    }

    MPI_Gatherv(localBucket.data(), local_size, MPI_INT,
        data.data(), recvCounts.data(), displs.data(), MPI_INT,
        0, MPI_COMM_WORLD);

    MPI_Bcast(data.data(), data.size(), MPI_INT, 0, MPI_COMM_WORLD);
}

void MPI_OddEven_Sort(std::vector<int>& data, const int rank, const int size)
{
    const int root = 0;
    const int tag = 0;
    const int dataSize = static_cast<int>(data.size());

    std::vector<int> sendcounts(size);
    std::vector<int> displs(size);
    int base = dataSize / size;
    int remainder = dataSize % size;
    int currentDispl = 0;

    for (int index = 0; index < size; index++) 
    {
        sendcounts[index] = base + (index < remainder ? 1 : 0);
        displs[index] = currentDispl;
        currentDispl += sendcounts[index];
    }

    int localSize = sendcounts[rank];
    std::vector<int> localData(localSize);

    MPI_Scatterv(data.data(), sendcounts.data(), displs.data(), MPI_INT,
        localData.data(), localSize, MPI_INT,
        root, MPI_COMM_WORLD);

    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int index = 0; index + 1 < localSize; index += 2) 
        {
            if (localData[index] > localData[index + 1]) 
            {
                std::swap(localData[index], localData[index + 1]);
                sorted = false;
            }
        }
        for (int index = 1; index + 1 < localSize; index += 2) 
        {
            if (localData[index] > localData[index + 1]) 
            {
                std::swap(localData[index], localData[index + 1]);
                sorted = false;
            }
        }
    }

    for (int phase = 0; phase < size; phase++) 
    {
        int partner = -1;
        if (phase % 2 == 0) 
        {
            if (rank % 2 == 0 && rank + 1 < size)
                partner = rank + 1;
            else if (rank % 2 == 1)
                partner = rank - 1;
        }
        else {
            if (rank % 2 == 1 && rank + 1 < size)
                partner = rank + 1;
            else if (rank % 2 == 0 && rank > 0)
                partner = rank - 1;
        }

        if (partner >= 0 && partner < size) 
        {
            int partnerSize = sendcounts[partner];
            std::vector<int> partnerData(partnerSize);

            MPI_Sendrecv(localData.data(), localSize, MPI_INT, partner, tag,
                partnerData.data(), partnerSize, MPI_INT, partner, tag,
                MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            std::vector<int> merged(localSize + partnerSize);
            std::merge(localData.begin(), localData.end(),
                partnerData.begin(), partnerData.end(),
                merged.begin());

            if (rank < partner) 
            {
                localData.assign(merged.begin(), merged.begin() + localSize);
            }
            else {
                localData.assign(merged.end() - localSize, merged.end());
            }
        }

        MPI_Barrier(MPI_COMM_WORLD);
    }

    MPI_Gatherv(localData.data(), localSize, MPI_INT,
        data.data(), sendcounts.data(), displs.data(), MPI_INT,
        root, MPI_COMM_WORLD);

    MPI_Bcast(data.data(), dataSize, MPI_INT, root, MPI_COMM_WORLD);
}

void MPI_Ranking_Sort(std::vector<int>& data, const int rank, const int size)
{
    int dataSize = static_cast<int>(data.size());
    MPI_Bcast(data.data(), dataSize, MPI_INT, 0, MPI_COMM_WORLD);

    std::vector<int> sendcounts(size);
    std::vector<int> displs(size);
    int base = dataSize / size;
    int remainder = dataSize % size;
    int currentDispl = 0;

    for (int index = 0; index < size; index++) 
    {
        sendcounts[index] = base + (index < remainder ? 1 : 0);
        displs[index] = currentDispl;
        currentDispl += sendcounts[index];
    }

    int localSize = sendcounts[rank];
    std::vector<int> localRanks(localSize, 0);

    for (int index = 0; index < localSize; index++) 
    {
        int globalIndex = displs[rank] + index;
        for (int jndex = 0; jndex < dataSize; jndex++) 
        {
            if (data[jndex] < data[globalIndex] || (data[jndex] == data[globalIndex] && jndex < globalIndex)) 
            {
                localRanks[index]++;
            }
        }
    }

    std::vector<int> globalRanks(dataSize);
    MPI_Gatherv(localRanks.data(), localSize, MPI_INT,
        globalRanks.data(), sendcounts.data(), displs.data(), MPI_INT,
        0, MPI_COMM_WORLD);

    if (rank == 0) 
    {
        std::vector<int> sortedData(dataSize);
        for (int index = 0; index < dataSize; index++) 
        {
            sortedData[globalRanks[index]] = data[index];
        }
        data = std::move(sortedData);
    }

    MPI_Bcast(data.data(), dataSize, MPI_INT, 0, MPI_COMM_WORLD);
}

void MPI_Shell_Sort(std::vector<int>& data, const int rank, const int size)
{
    int dataSize = data.size();

    std::vector<int> sendcounts(size);
    std::vector<int> displs(size);
    int base = dataSize / size;
    int remainder = dataSize % size;
    int currentDispl = 0;

    for (int index = 0; index < size; index++) 
    {
        sendcounts[index] = base + (index < remainder ? 1 : 0);
        displs[index] = currentDispl;
        currentDispl += sendcounts[index];
    }

    int start = displs[rank];
    int end = start + sendcounts[rank];
    std::vector<int> localData(data.begin() + start, data.begin() + end);

    for (int gap = localData.size() / 2; gap > 0; gap /= 2) 
    {
        for (int index = gap; index < localData.size(); index++) 
        {
            int temp = localData[index];
            int jndex;
            for (jndex = index; jndex >= gap && localData[jndex - gap] > temp; jndex -= gap) 
            {
                localData[jndex] = localData[jndex - gap];
            }
            localData[jndex] = temp;
        }
    }

    int localSorted = std::is_sorted(localData.begin(), localData.end()) ? 1 : 0;
    int allSorted;
    MPI_Allreduce(&localSorted, &allSorted, 1, MPI_INT, MPI_LAND, MPI_COMM_WORLD);

    MPI_Gatherv(localData.data(), localData.size(), MPI_INT,
        data.data(), sendcounts.data(), displs.data(), MPI_INT,
        0, MPI_COMM_WORLD);

    if (rank == 0 && (!allSorted || !std::is_sorted(data.begin(), data.end()))) 
    {
        std::sort(data.begin(), data.end());
    }

    MPI_Bcast(data.data(), data.size(), MPI_INT, 0, MPI_COMM_WORLD);
}

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int option = 0;
    std::vector<int> data;
    int dataSize = 0;

    if (rank == 0)
    {
        std::cout << "1.Direct Sort\n";
        std::cout << "2.Bucket Sort\n";
        std::cout << "3.Odd-Even Sort\n";
        std::cout << "4.Ranking Sort\n";
        std::cout << "5.Shell Sort\n";
        std::cout << "Enter sorting algorithm (1-5): ";
        std::cin >> option;
    }

    MPI_Bcast(&option, 1, MPI_INT, 0, MPI_COMM_WORLD);

    auto selectedAlgorithm = static_cast<SortAlgorithm>(option);

    if (selectedAlgorithm == SortAlgorithm::Invalid)
    {
        if (rank == 0)
        {
            std::cout << "Invalid sorting algorithm selected.\n";
        }
        MPI_Finalize();
        return 1;
    }

    if (rank == 0)
    {
        data = ReadDataFromFile("input.txt");
        dataSize = static_cast<int>(data.size());
        if (data.empty()) 
        {
            std::cerr << "No data loaded. Exiting.\n";
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    MPI_Bcast(&dataSize, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank != 0) 
    {
        data.resize(dataSize);
    }
    MPI_Bcast(data.data(), dataSize, MPI_INT, 0, MPI_COMM_WORLD);

    double start_time = 0;
    if (rank == 0) 
    {
        start_time = MPI_Wtime();
    }

    switch (selectedAlgorithm)
    {
        case SortAlgorithm::DirectSort:
            MPI_Direct_Sort(data, rank, size);
            break;
        case SortAlgorithm::BucketSort:
            MPI_Bucket_Sort(data, rank, size);
            break;
        case SortAlgorithm::OddEvenSort:
            MPI_OddEven_Sort(data, rank, size);
            break;
        case SortAlgorithm::RankingSort:
            MPI_Ranking_Sort(data, rank, size);
            break;
        case SortAlgorithm::ShellSort:
            MPI_Shell_Sort(data, rank, size);
            break;
        default:
            if (rank == 0) 
            {
                std::cout << "Invalid sorting algorithm selected.\n";
            }
            MPI_Finalize();
            return 1;
    }

    if (rank == 0)
    {
        double executionTime = MPI_Wtime() - start_time;
        bool isSorted = std::is_sorted(data.begin(), data.end());
        std::cout << EnumToString(selectedAlgorithm) << " with " << size << " processes: " << executionTime<<"\n";
        std::cout << "Status: " << isSorted <<"\n";
    }

    MPI_Finalize();
    return 0;
}