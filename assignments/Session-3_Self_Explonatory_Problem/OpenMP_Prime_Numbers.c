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
