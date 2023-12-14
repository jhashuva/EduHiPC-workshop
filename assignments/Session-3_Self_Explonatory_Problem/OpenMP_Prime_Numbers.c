/*
### Q. 1 **OpenMP Prime Numbers:** Write a parallel program using OpenMP to count the number of prime numbers up to 
a given limit (**`NUM`**). 
The program should utilize parallel processing to efficiently check the primality of numbers using 
the provided **`isprime`** function.

**Requirements:**

1. Implement the **`isprime`** function to determine whether a given number is prime.
2. Use OpenMP directives to create a parallel region and distribute the loop iterations among multiple threads.
3. Implement a reduction operation to accumulate the count of prime numbers.
4. The program should be able to handle different values of **`NUM`** for experimentation.
5. Print the total number of prime numbers found within the specified range.
*/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void findPrimes(int n, int **arr) {
    int count = 0;
    #pragma omp parallel for
    for (int i = 2; i <= n; i++) {
        int flag = 1;
        for (int j = 2; j <= i / 2+1; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            //printf("%d\n", i);
            (*arr)[count++] = i; // Storing prime number in the array
        }

    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int)); // Dynamic memory allocation

    #pragma omp parallel
    {
        #pragma omp single
        {
          findPrimes(n, &arr);
        }

    }


    // Optional: Print the primes stored in the array
    printf("Primes up to %d:\n", n);
    for (int i = 0; arr[i] != 0 && i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); //free dynamically allocated memory

    return 0;
}
