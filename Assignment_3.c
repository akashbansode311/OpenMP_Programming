/*Write a C program to calculate the sum of all elements of an integer array.

Implement the calculation using OpenMP and display the thread that processes each element.

#include <stdio.h>

#define N 10

int main()
{
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum = sum + A[i];

        printf("Processing A[%d] = %d\n", i, A[i]);
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
*/

#include <stdio.h>
#include <omp.h>

#define N 10

int main()
{
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
    {
        sum = sum + A[i];

        printf("Thread %d processes A[%d] = %d\n",
               omp_get_thread_num(), i, A[i]);
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
