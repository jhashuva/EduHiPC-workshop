/*
Nested Parallelism : Implement a program that explores nested parallelism using OpenMP. The program initializes a nested parallel region, and at each level, it reports the number of threads in the team and the thread ID. The goal is to understand how nested parallel regions affect the team structure and thread assignments.**

**Task :**

1. The program starts with an outer parallel region with two threads. In this region, each thread calls the `report_num_threads` function at level 1, reporting the number of threads in the team and the thread ID.
2. Inside the outer parallel region, a nested parallel region is created again with two threads. Within this region, each thread calls the `report_num_threads` function at level 2, providing information about the number of threads in the team and the thread ID at this level.
3. Further, another level of nested parallelism is introduced within the level 2 region. Each thread in this level 2 region reports the number of threads in its team and its own thread ID using the **`report_num_threads`** function at level 3.
*/
#include <omp.h>
#include <stdio.h>
void report_num_threads(int level)
{
    #pragma omp single
    {
        printf("Level %d: number of threads in the team - %d, thread id = %d\n",
                  level, omp_get_num_threads(),omp_get_thread_num());
    }
 }
int main()
{
    omp_set_dynamic(0); //disable dynamic adjustment of the number of threads
    #pragma omp parallel num_threads(2)
    {
        report_num_threads(2);
        #pragma omp parallel num_threads(2)
        {
            report_num_threads(2);
            #pragma omp parallel num_threads(2)
            {
                report_num_threads(3);
            }
        }
    }
    return(0);
}
