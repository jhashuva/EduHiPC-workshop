/*
Parallelizing SAXPY : The given SAXPY operation is defined as  $zi​=a⋅xi​+y$  for each element i in array z, x and a scalar y. The goal is to parallelize SAXPY operation using OpenMP to improve performance.**

**Task:**

1. Modify the given C code to parallelize the SAXPY operation using OpenMP directives.
2. Ensure correct synchronization and avoid race conditions during parallel execution.
3. Experiment with different OpenMP constructs and clauses to optimize the parallel performance.
4. Validate the correctness of the parallelized code by comparing the results with the original sequential implementation.

**Requirements:**

1. Use OpenMP directives to parallelize the SAXPY loop.
2. Implement proper data-sharing clauses to avoid race conditions and ensure correctness.
3. Experiment with adjusting the number of threads to find an optimal configuration.
4. Measure and compare the execution time of the parallelized code with the sequential version.

**Note:**

- SAXPY operation: zi=a⋅xi+y
- Array x and z have n elements.
- Scalar a is a constant
- Scalar y is a constant
- Ensure that the parallelized code produces correct results and exhibits performance improvements.
*/
#include <stdio.h>
// Add the requried parallel pargram 
void saxpy(float z[], float a, float x[], float y, int n) {
     //Declare required variables
    
     // Calculate chunk size to evenly distribute the work among threads


     // Calculate the starting and ending indices for each thread

     
    // Perform SAXPY within the assigned range
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y;
    }
}

int main() {
    
    int n = 5;
    float z[n];
    float a = 2.0;
    float x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y = 10.0;

    saxpy(z, a, x, y, n);

    // Print the result
    printf("Resulting array z: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", z[i]);
    }
    printf("\n");

    return 0;
}
