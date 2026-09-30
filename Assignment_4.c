/*Calculate the sum of an array using multiple threads. Each thread uses a private temporary variable, and the final result is combined using reduction.

#include <stdio.h>

#define N 10

int main()
{
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    int temp;

    for (int i = 0; i < N; i++)
    {
        temp = A[i];

        printf("Processing A[%d] = %d\n", i, temp);

        sum += temp;
    }

    printf("\nFinal Sum = %d\n", sum);

    return 0;
}

*/


#include <stdio.h>
#include <omp.h>

#define N 10

int main()
{
    int A[N] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    int i;
    int temp;

    #pragma omp parallel for private(temp) reduction(+:sum)
    for (i = 0; i < N; i++)
    {
        temp = A[i];

        printf("Thread %d processes A[%d] = %d\n",
               omp_get_thread_num(), i, temp);

        sum += temp;
    }

    printf("\nFinal Sum = %d\n", sum);

    return 0;
}
