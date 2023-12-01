/*
OpenMP Greeting Message: Write a parallel program using OpenMP to print a greeting message from multiple threads. Each thread should print its own greeting message, including its thread ID. The program should use the OpenMP parallel construct to create a parallel region, and each thread within that region should print a unique message.

**Requirements:**

1. The program should use OpenMP directives to create a parallel region.
2. Each thread should print a greeting message that includes its thread ID.
3. Compile the program with OpenMP support.
4. Ensure that the output shows messages from multiple threads.

**Example Output:**

Hello from thread 0
Hello from thread 2
Hello from thread 1
Hello from thread 3
 

Note: The order of the messages may vary as it depends on the operating system's thread scheduling.
*/

#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }

    return 0;
}

