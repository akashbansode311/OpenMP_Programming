/*Write a C program to add two integer arrays A and B element-by-element and store the result in array C.

First implement the operation using a normal serial for loop, and then parallelize the loop using the OpenMP parallel for construct.

#include <stdio.h>

#define N 10

int main()
{
    int A[N], B[N], C[N];

    // Initialize arrays
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
        B[i] = (i + 1) * 10;
    }

    // Serial vector addition
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }

    // Print result
    printf("Result:\n");

    for (int i = 0; i < N; i++)
    {
        printf("C[%d] = %d\n", i, C[i]);
    }

    return 0;
}

*/


#include <stdio.h>
#include <omp.h>

#define N 10

int main()
{
    int A[N], B[N], C[N];

    // Initialize arrays
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
        B[i] = (i + 1) * 10;
    }

    // Parallel vector addition
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];

        printf("Thread %d calculates C[%d] = %d\n",
               omp_get_thread_num(), i, C[i]);
    }

    // Print final result
    printf("\nResult:\n");

    for (int i = 0; i < N; i++)
    {
        printf("C[%d] = %d\n", i, C[i]);
    }

    return 0;
}
