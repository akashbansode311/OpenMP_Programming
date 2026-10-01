/*
Write a C program to multiply two square matrices. Implement both serial and OpenMP-parallel versions, measure their execution times, and compare their performance.

#include <stdio.h>
#include <time.h>

#define N 2000

void matmul_serial(double A[N][N], double B[N][N], double C[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            C[i][j] = 0.0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    static double A[N][N];
    static double B[N][N];
    static double C[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    matmul_serial(A, B, C);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed_time =
        (end.tv_sec - start.tv_sec) +
        (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Serial Matrix Multiplication\n");
    printf("Matrix Size = %d x %d\n", N, N);
    printf("C[0][0] = %f\n", C[0][0]);
    printf("Serial Time = %f seconds\n", elapsed_time);

    return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 2000

void matmul_omp(double A[N][N], double B[N][N], double C[N][N]) {

    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    static double A[N][N], B[N][N], C[N][N];
    double start, end;

    // Init
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }

    start = omp_get_wtime();
    matmul_omp(A, B, C);
    end = omp_get_wtime();

    printf("OpenMP Time: %f sec\n", end - start);

    return 0;
}
