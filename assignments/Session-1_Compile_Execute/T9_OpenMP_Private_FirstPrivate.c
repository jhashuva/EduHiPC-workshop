/*
Data Scoping with Private and Firstprivate :** You are tasked with developing a program that showcases the use of `private` and `firstprivate` clauses in OpenMP for data scoping within a parallel region. The program should illustrate how these clauses affect the behavior of shared and private variables in the context of parallel execution.

**Requirements:**

1. Declare a shared integer variable (**`shared_variable`**) initialized to zero.
2. Declare a private integer variable (**`private_variable`**) initialized to zero.
3. Implement a parallel region using the OpenMP **`parallel`** directive.
4. Use the **`shared`** clause to designate the shared variable within the parallel region.
5. Use the **`private`** clause to designate the private variable within the parallel region without initializing it.
6. Use the **`firstprivate`** clause to designate the shared variable within the parallel region, initializing the private copies with the original shared value.
7. Create a loop using the OpenMP **`for`** directive to increment the shared and private variables independently.
8. Print the values of the shared and private variables within the loop to observe their behavior with multiple threads.
9. Print the final values of the shared and private variables after the parallel region to observe the impact of data scoping.
*/
#include <stdio.h>
#include <omp.h>

int main() {
    int shared_variable = 0;
    int private_variable = 0;

    #pragma omp parallel shared(shared_variable) private(private_variable)
    {
        int thread_id = omp_get_thread_num();

        // Increment the shared variable without using a private copy
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            shared_variable += 1;
            printf("Thread %d - Shared Variable: %d\n", thread_id, shared_variable);
        }

        // Increment a private variable initialized with the original shared value
        #pragma omp for private(private_variable) firstprivate(shared_variable)
        for (int i = 0; i < 5; i++) {
            private_variable = shared_variable;  // Initialize private copy with the original shared value
            private_variable += 1;
            printf("Thread %d - Private Variable: %d\n", thread_id, private_variable);
        }

        // Output the final values of shared and private variables
        printf("Thread %d - Final Shared Variable: %d\n", thread_id, shared_variable);
        printf("Thread %d - Final Private Variable: %d\n", thread_id, private_variable);
    }

    return 0;
}
