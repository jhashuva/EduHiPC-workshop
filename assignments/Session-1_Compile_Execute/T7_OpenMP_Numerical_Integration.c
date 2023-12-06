/*
Numerical Integration : Develop a parallel program in C using OpenMP to numerically calculate the integral of the sine function over a specified range. Ensure the accuracy of the result and employ OpenMP directives for parallelization.**

**Requirements:**

**Problem Statement: Parallel Numerical Integration with OpenMP**

Develop a parallel program in C using OpenMP to numerically calculate the integral of the sine function over a specified range. Ensure the accuracy of the result and employ OpenMP directives for parallelization.

**Specifications:**

1. Implement a numerical integration algorithm for the sine function using the given formula:

    $$
    \int_{0}^\varPi\sin{(x)}dx
    $$

2. The integration should be performed over a specified number of steps (*steps*) to discretize the integral.
3. Utilize OpenMP directives to parallelize the computation of the integral. Specifically, apply **`#pragma omp parallel for`** to distribute the workload among multiple threads.
4. Use a critical section (**`#pragma omp critical`**) to ensure that the shared variable **`total`** is updated safely during the parallel computation.
5. The **`total`** variable should accumulate the partial results obtained by each thread.
6. Print the final result of the integral after all threads have completed their computation

Note: if compiler gives error use : `gcc -lm -fopenmp <file_name>.c -o <file_name>`
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv) {
   int steps = 1000;
   float delta = M_PI/steps;
   float total = 0.0;
   int i;
   #pragma omp parallel for
   for (i=0; i<steps; i++) {
      #pragma omp critical
      total = total + sin(delta*i) * delta;
   }
   printf("The integral of sine from 0 to Pi is %f\n", total);
}
