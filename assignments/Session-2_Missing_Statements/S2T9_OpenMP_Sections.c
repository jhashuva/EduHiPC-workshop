/*
Parallel Sections: You are tasked with developing a program that utilizes the OpenMP **`sections`** directive to execute multiple sections of code in parallel. The program should consist of three sections, each represented by a separate function, and these sections should be executed concurrently by different threads.

**Requirements:**

1. Implement three functions, `section1`, `section2`, and `section3`, each containing a distinct set of instructions or computations.
2. Use the OpenMP **`sections`** directive to parallelize the execution of these functions. Each function should be enclosed within the **`#pragma omp section`** directive.
3. Ensure proper thread synchronization and manage parallel execution using the OpenMP runtime environment.
4. Display relevant information, such as the thread ID, within each section to observe concurrent execution.
*/
#include <stdio.h>
#include <omp.h>

void section1() {
    {
        printf("Section 1: Thread ID = %d\n", omp_get_thread_num());
        // Add relevant instructions for section 1
        for(int i=0;i<4;i++){
            printf("Section 1, Thread Id=%d,---%d\n",omp_get_team_num(),i);
        }
    }
}

void section2() {
    {
        printf("Section 2: Thread ID = %d\n", omp_get_thread_num());
        // Add relevant instructions for section 2
          for(int i=0;i<5;i++){
            printf("Section 1, Thread Id=%d,---%d\n",omp_get_team_num(),i);
        }
    }
}

void section3() {
    {
        printf("Section 3: Thread ID = %d\n", omp_get_thread_num());
        // Add relevant instructions for section 3
         for(int i=0;i<6;i++){
            printf("Section 1, Thread Id=%d,---%d\n",omp_get_team_num(),i);
        }
    }
}

int main() {
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            section1();
            #pragma omp section
            section2();
            #pragma omp section
            section3();
        }
    }

    return 0;
}
