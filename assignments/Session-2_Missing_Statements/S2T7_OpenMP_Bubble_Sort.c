/*
Parallel Bubble Sort :  You are tasked with developing a parallelized version of the Bubble Sort algorithm using OpenMP. Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

**Requirements:**

1. Implement the Bubble Sort algorithm in C.
2. Use OpenMP directives to parallelize the outer loop of the Bubble Sort algorithm. The goal is to achieve parallel execution of the independent iterations of the outer loop.
3. Ensure that each thread has its private copy of loop variables to prevent data race conditions.
4. Test the program with a sample array and display the original and sorted arrays.
*/
#include <stdio.h>
#include <omp.h>

void bubble_sort(int arr[], int n) {
    int i, j;

    #pragma omp parallel for private(j) shared(arr)
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // add your Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

int main() {
    // Your main function to test the parallel Bubble Sort
    // ...
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
