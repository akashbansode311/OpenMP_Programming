#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    int x = 100;

    printf("Before parallel region: x = %d\n", x);

    #pragma omp parallel firstprivate(x)
    {
        printf("Thread %d sees x = %d\n",omp_get_thread_num(), x);

        x = omp_get_thread_num();

        printf("And updates its value to %d\n", x);
    }

    printf("After parallel region: x = %d\n", x);

    return 0;
}
