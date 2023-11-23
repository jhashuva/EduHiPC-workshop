//%compiler: clang
//%cflags: -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/*
“#pragma omp parallel num_threads(4)” still means
that the subsequent statement will be executed by multiple
threads in parallel, but the number of threads is 4 .*/
int main(int argc, char *argv[]){
    #pragma omp parallel num_threads(10)
    printf("%s\n", "Hello World");

    return 0;
}
