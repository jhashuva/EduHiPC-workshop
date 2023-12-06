/*
You are tasked with developing a parallel program in C using OpenMP to calculate the average of an array of integers. The program should efficiently distribute the workload among multiple threads, and you must handle critical sections appropriately to avoid data races and ensure accurate results.

**Requirements:**

1. Create an array of integers named **`array`** with a size of **`ARRAY_SIZE`**, and initialize it with values ranging from 1 to **`ARRAY_SIZE`**.
2. Design a parallel region using OpenMP directives to distribute the array summation across multiple threads. Utilize the **`#pragma omp parallel`** and **`#pragma omp for`** directives for parallel execution.
3. Each thread should compute its local sum by iterating over a subset of the array elements.
4. Implement a critical section using the `#pragma omp critical` directive to safely update a shared `sum` variable with each thread's local sum.
5. After the parallel region, calculate the average by dividing the total sum by the size of the array.
6. Print the computed average.
*/
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000

int main() {
    const int num_threads = 4;
    int array[ARRAY_SIZE];
    double sum = 0.0;

    // Initialize the array with values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i + 1;
    }

    #pragma omp parallel num_threads(num_threads) shared(sum)
    {
        double local_sum = 0.0;

        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            local_sum += array[i];
        }

        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    double average = sum / ARRAY_SIZE;

    printf("Average: %f\n", average);

    return 0;
}
