#include <iostream>
#include <cstdlib>
#include <omp.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <threads>" << std::endl;
        return 1;
    }

    // Parse command-line arguments
    int n = std::atoi(argv[1]);
    int num_threads = std::atoi(argv[2]);

    // Create an array and initialize it
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;  // Initializing with values from 1 to n
    }

    // Shared variable to store the sum
    int total = 0;

    // Parallel region with specified number of threads
    #pragma omp parallel num_threads(num_threads) shared(total)
    {
        // Calculate the starting and ending indices for each thread
        int thread_id = omp_get_thread_num();
        int chunk_size = n / num_threads;
        int start_index = thread_id * chunk_size;
        int end_index = (thread_id == num_threads - 1) ? n : (thread_id + 1) * chunk_size;

        // Each thread sums its portion of the array
        int local_sum = 0;
        for (int i = start_index; i < end_index; ++i) {
            local_sum += arr[i];
        }

        // Accumulate local sums into the shared total using a critical section
        #pragma omp critical
        {
            total += local_sum;
        }
    }

    // Output the final result
    std::cout << "Sum of array elements: " << total << std::endl;

    // Clean up
    delete[] arr;

    return 0;
}
