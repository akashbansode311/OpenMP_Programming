#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main()
{
    double *A;
    long long sum = 0;
    double start, end;

    A = malloc(N * sizeof(double));

    for (long i = 0; i < N; i++)
        A[i] = 1.0;

    start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < N; i++)
        sum += A[i];

    end = omp_get_wtime();

    printf("Sum = %lld\n", sum);
    printf("Parallel Time = %f seconds\n", end - start);

    free(A);

    return 0;
}
