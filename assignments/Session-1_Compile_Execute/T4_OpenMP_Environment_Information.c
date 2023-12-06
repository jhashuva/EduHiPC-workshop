/*
OpenMP Environment Information: Design a parallel program using OpenMP that leverages appropriate OpenMP routines or functions to query and print essential information about the OpenMP execution environment. The program should be structured to extract the following details, particularly focusing on the master thread:

1. The number of processors available.
2. The number of threads currently in use.
3. The maximum number of threads that can be utilized.
4. Determine if the execution is currently within a parallel region.
5. Check and display if dynamic threads are enabled.
6. Verify and print whether nested parallelism is supported.

**Requirements:**

1. Use OpenMP routines or functions to gather information about the OpenMP execution environment.
2. Implement the necessary queries inside the master thread.
3. Display the gathered information clearly, indicating the purpose of each output.
4. Account for potential variations in the implementation of Fortran functions (e.g., some compilers may use integers instead of logical values).
*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
int nthreads, tid, procs, maxt, inpar, dynamic, nested;

/* Start parallel region */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();

  /* Only master thread does this */
  if (tid == 0)
    {
    printf("Thread %d getting environment info...\n", tid);

    /* Get environment information */
    procs = omp_get_num_procs();
    nthreads = omp_get_num_threads();
    maxt = omp_get_max_threads();
    inpar = omp_in_parallel();
    dynamic = omp_get_dynamic();
    nested = omp_get_nested();

    /* Print environment information */
    printf("Number of processors = %d\n", procs);
    printf("Number of threads = %d\n", nthreads);
    printf("Max threads = %d\n", maxt);
    printf("In parallel? = %d\n", inpar);
    printf("Dynamic threads enabled? = %d\n", dynamic);
    printf("Nested parallelism supported? = %d\n", nested);

    }

  }  /* Done */

}
