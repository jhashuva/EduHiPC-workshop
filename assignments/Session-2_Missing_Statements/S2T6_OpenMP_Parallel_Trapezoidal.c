/*
Parallel Trapezoidal Rule: You are tasked with developing a parallel program to numerically integrate a given function over a specified interval using the trapezoidal rule. The trapezoidal rule is a numerical integration technique that approximates the definite integral of a function by dividing the interval into small trapezoids and summing their areas.**

**Requirements:**

1. Define a function **`func(x)`** that represents the mathematical function to be integrated. In the provided example, the function is **`x * x`**, but you can modify it based on the specific function you are working with.
2. Implement a function **`trapezoidal_rule`** that takes as input the interval **`[a, b]`** and the number of trapezoids **`n`**. This function should use OpenMP to parallelize the computation of the trapezoidal rule.
3. Utilize the OpenMP **`parallel for`** directive to parallelize the loop that calculates the sum of function values.
4. Use the OpenMP **`reduction(+:integral)`** clause to ensure the correct summation of partial results from different threads.
5. Test your program by integrating the provided function over a specified interval. You may adjust the values of **`a`**, `b`, and `n` in the `main` function for testing.

Note: Be mindful of data race conditions and use appropriate synchronization mechanisms if needed.
*/
#include <stdio.h>
#include <omp.h>

double func(double x) {
    // Define the function to be integrated
    return x * x;
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = 0.0;

    //add the required directive here
    #pragma omp parallel for
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        double f_x = func(x);
        integral += f_x;
    }

    integral += 0.5 * (func(a) + func(b)) * h;

    return integral;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000000;

    double result = trapezoidal_rule(a, b, n);

    printf("Result of integration: %f\n", result);

    return 0;
}
