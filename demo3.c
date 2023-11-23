//%compiler: clang
//%cflags: -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
    int M =10;
    //case 1
    #pragma omp parallel num_threads(4)
    printf("Hello World in case 1 from thread %d\n", omp_get_thread_num());

    printf("-------------------------------------------------\n");

    //case 2
    #pragma omp parallel num_threads(4) if(M > 10)
    printf("Hello World in case 2 from thread %d\n", omp_get_thread_num());

    printf("-------------------------------------------------\n");

    //case 3
    #pragma omp parallel num_threads(4) if(M <= 10)
    printf("Hello World in case 3 from thread %d\n", omp_get_thread_num());

    return 0;
}
