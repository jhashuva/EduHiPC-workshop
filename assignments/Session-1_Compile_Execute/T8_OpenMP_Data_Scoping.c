/*
OpenMP Data Scoping : You are tasked with developing a program that illustrates the concept of data scoping in OpenMP. The program should use shared and private variables within a parallel region to demonstrate how these variables behave when accessed by multiple threads.

**Requirements:**

1. Declare a shared integer variable (`shared_variable`) initialized to zero.
2. Declare a private integer variable (`private_variable`) initialized to zero.
3. Implement a parallel region using the OpenMP `parallel` directive.
4. Use the **`shared`** clause to designate the shared variable within the parallel region.
5. Use the **`private`** clause to designate the private variable within the parallel region.
6. In the parallel region, create a loop using the OpenMP `for` directive to increment the shared and private variables independently.
7. Print the values of the shared and private variables within the loop to observe their behavior with multiple threads.
8. Print the final values of the shared and private variables after the parallel region to observe the impact of data scoping.
*/
#include <stdio.h>
#include <omp.h>

int main() {
    int shared_variable = 0;
    int private_variable = 0;

    #pragma omp parallel shared(shared_variable) private(private_variable)
    {
        int thread_id = omp_get_thread_num();

        // Each thread increments the shared variable
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            shared_variable += 1;
            printf("Thread %d - Shared Variable: %d\n", thread_id, shared_variable);
        }

        // Each thread increments its private variable
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            private_variable += 1;
            printf("Thread %d - Private Variable: %d\n", thread_id, private_variable);
        }
    }

    // Output the final values after parallel execution
    printf("Final Shared Variable: %d\n", shared_variable);
    printf("Final Private Variable: %d\n", private_variable);

    return 0;
}
