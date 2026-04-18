#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);
    int x = 10;
    printf("Value before entering into the Parallel Region : %d\n", x);
    #pragma omp parallel private(x)
    {
        printf("Thread %d: x = %d\n", omp_get_thread_num(), x);
    }

    return 0;
}
