/*
Design a parallel program in C using OpenMP to perform a linear search on an array. The goal is to efficiently search for a specific target value in the array while utilizing parallelism for improved performance. Handle critical sections appropriately to ensure the correct identification of the target value's position.

**Requirements:**

1. Implement a linear search algorithm using a function named `linearSearch`. This function should take an array, its size, and a target value as parameters.
2. Utilize OpenMP directives to parallelize the search loop within the `linearSearch` function. Specifically, use `#pragma omp parallel for` to allow multiple threads to search different parts of the array concurrently.
3. Use a critical section (**`#pragma omp critical`**) to ensure that the result variable is updated safely when the target value is found. The result variable should store the position of the target value in the array.
4. In the `main` function, initialize an array of integers and perform a linear search for a specified target value using the `linearSearch` function.
5. Print the result of the search, indicating whether the target value was found and its position if found.
*/
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000
#define SEARCH_VALUE 42

int linearSearch(int *arr, int size, int target) {
    int result = -1;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            #pragma omp critical
            {
                result = i;  // Set result only once using a critical section
            }
        }
    }

    return result;
}

int main() {
    int array[ARRAY_SIZE];

    // Initialize the array with values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i;
    }

    int position = linearSearch(array, ARRAY_SIZE, SEARCH_VALUE);

    if (position != -1) {
        printf("Value %d found at position %d.\n", SEARCH_VALUE, position);
    } else {
        printf("Value %d not found in the array.\n", SEARCH_VALUE);
    }

    return 0;
}
