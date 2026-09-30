#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000000

int main()
{
    double *A;
    long long sum = 0;
    clock_t start, end;

    A = malloc(N * sizeof(double));

    for (long i = 0; i < N; i++)
        A[i] = 1.0;

    start = clock();

    for (long i = 0; i < N; i++)
        sum += A[i];

    end = clock();

    printf("Sum = %lld\n", sum);
    printf("Serial Time = %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    free(A);

    return 0;
}
