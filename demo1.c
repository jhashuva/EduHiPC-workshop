//%compiler: clang
//%cflags: -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/* #pragma omp parallel” indicates that the subsequent statement will be executed by multiple threads in parallel,
and the number of threads is preset by the system (generally equal to the number of logical processors, for example,
i5 4-core 8-thread CPU has 8 logical processors),*/
int main(int argc, char *argv[]){
    #pragma omp parallel
    printf("%s\n", "Hello World");

    return 0;
}
