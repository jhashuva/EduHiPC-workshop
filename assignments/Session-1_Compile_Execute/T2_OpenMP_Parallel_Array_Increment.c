/*
Parallel Array Increment : You are given an array `shared_array` of size `ARRAY_SIZE`. Multiple threads need to concurrently increment each element of the array. Design a parallel program using OpenMP to achieve this, ensuring that the increments are performed atomically to avoid race conditions.

**Requirements:**

1. The array **`shared_array`** is initialized to zeros.
2. Use OpenMP directives to parallelize the array increment operation across multiple threads.
3. Ensure that each thread increments all elements of the array.
4. Use the **`#pragma omp atomic`** directive to perform atomic increments on each array element.
5. Print the final values of the array after all threads have completed their increments.

Example Output:

> Final Array Values: 1 1 1 1 1 1 1 1 1 1

*/

#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 10

int main() {
    const int num_threads = 4;
    int shared_array[ARRAY_SIZE];

   // Initialize the array to zeros
    for (int i = 0; i < ARRAY_SIZE; ++i) {
         shared_array[i] = 0;
         }

   #pragma omp parallel num_threads(num_threads)
   {
   // Each thread increments all elements in the array
   #pragma omp for
   for (int i = 0; i < ARRAY_SIZE; ++i) {
    #pragma omp atomic
       shared_array[i]++;
      }
    }
    // Print the final values in the array
    printf("Final Array Values: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
    printf("%d ", shared_array[i]);
    }
    printf("\n");
    return 0;
   }
