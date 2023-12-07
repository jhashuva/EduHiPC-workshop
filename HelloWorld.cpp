#include <iostream>

#include <cstdlib>

#include <omp.h>
int main(int argc, char *argv[])

{

int p = atoi(argv[1]);

#pragma omp parallel num_threads(p)

{

int thread_count = omp_get_num_threads();

int my_id = omp_get_thread_num();

std::cout << "Hello World from " << my_id << "of" << thread_count << std::endl;

}

return 0;

}
