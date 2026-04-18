#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    int x = 100;

    printf("Before parallel region: x = %d\n", x);

    #pragma omp parallel for lastprivate(x)
    for(int i = 0; i < 4; i++)
    {
        x = i;   // each iteration updates val

        printf("Thread %d handles i = %d, x = %d\n",
               omp_get_thread_num(), i, x);
    }

    printf("After parallel region value of x: = %d\n", x);

    return 0;
}
