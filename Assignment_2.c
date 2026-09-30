/*Write a C program to add two matrices A and B of the same size and store the result in matrix C.


#include <stdio.h>

#define ROWS 4
#define COLS 4

int main()
{
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int C[ROWS][COLS];

    // Initialize matrices
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            A[i][j] = i + j + 1;
            B[i][j] = (i + 1) * 10 + j;
        }
    }

    // Serial matrix addition
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    printf("Result Matrix C:\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

*/

#include <stdio.h>
#include <omp.h>

#define ROWS 4
#define COLS 4

int main()
{
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int C[ROWS][COLS];

    // Initialize matrices
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            A[i][j] = i + j + 1;
            B[i][j] = (i + 1) * 10 + j;
        }
    }

    // Parallel matrix addition
    #pragma omp parallel for
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            C[i][j] = A[i][j] + B[i][j];

            printf("Thread %d calculates C[%d][%d] = %d\n",
                   omp_get_thread_num(), i, j, C[i][j]);
        }
    }

    // Print result
    printf("\nResult Matrix C:\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
