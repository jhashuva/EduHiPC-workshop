/*
Parallelizing Exponential Function Calculation : The provided C code calculates the exponential function for each element in an array sequentially. The goal is to parallelize this computation using OpenMP to achieve better performance on multi-core systems.

**Task:**

1. Modify the given C code to parallelize the loop that calculates the exponential function for each element in the array.
2. Use OpenMP directives to parallelize the loop efficiently, ensuring proper synchronization and avoiding race conditions.
3. Experiment with different OpenMP constructs and clauses to optimize the parallel performance.
4. Validate the correctness of the parallelized code by comparing the results with the original sequential implementation.
5. Measure and compare the execution time of the parallelized code with the sequential version.

**Requirements:**

1. Use OpenMP directives to parallelize the loop.
2. Implement proper data-sharing clauses to avoid race conditions and ensure correctness.
3. Experiment with adjusting the number of threads to find an optimal configuration.
4. Measure and compare the execution time of the parallelized code with the sequential version using appropriate timing functions.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    // Allocate memory for the array
    double *x = (double*)malloc(N * sizeof(double));


    // Initialize the array
    for (int i = 0; i < N; i++) {
        x[i] = i * 0.01;  // Adjust the initialization as needed
    }

    // Measure execution time for the sequential code
    double start_sequential = omp_get_wtime();

    // Sequentially calculate the exponential function for each element
    for (int i = 0; i < N; i++) {
        x[i] = exp(x[i]);
    }

    // Measure execution time for the sequential code
    double end_sequential = omp_get_wtime();
    printf("Sequential Execution Time: %f seconds\n", end_sequential - start_sequential);
    printf("Original array values: %f, %f, %f, ..., %f\n", x[0], x[1], x[2], x[N - 1]);

    // Experiment with different thread counts
    for (int num_threads = 1; num_threads <= 5; num_threads++) {
        // Set the number of threads
        omp_set_num_threads(num_threads);

        // Measure execution time
        double start_time = omp_get_wtime();
        // Initialize the array
        #pragma omp parallel for shared(x)
        for (int i = 0; i < N; i++) {
            x[i] = i * 0.01;  // Adjust the initialization as needed
        }


        // Parallelize the loop to calculate the exponential function for each element
        #pragma omp parallel for shared(x)
        for (int i = 0; i < N; i++) {
            x[i] = exp(x[i]);
        }

        // Measure execution time
        double end_time = omp_get_wtime();

        // Print results
        printf("Thread Count: %d, Execution Time: %f seconds\n", num_threads, end_time - start_time);
        // Print some results for verification
        printf("Original array values: %f, %f, %f, ..., %f\n", x[0], x[1], x[2], x[N - 1]);
    }



    // Free allocated memory
    free(x);

    return 0;
}
