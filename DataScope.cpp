#include <iostream>
#include <cstdlib>
#include <omp.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_threads>" << std::endl;
        return 1;
    }

    int total = 0;
    int p = atoi(argv[1]);

    #pragma omp parallel num_threads(p)
    {
        int x = 0;
        int thread_count = omp_get_num_threads();
        int my_id = omp_get_thread_num();
        x = (my_id + 1) * thread_count;
        total = total + x;
        std::cout << "Id = " << my_id << " x = " << x << std::endl;
    }

    std::cout << "Total = " << total << std::endl;

    return 0;
}
