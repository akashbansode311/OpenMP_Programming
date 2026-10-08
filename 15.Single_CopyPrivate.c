#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    int x = 0;

    #pragma omp parallel private(x)
    {
        #pragma omp single copyprivate(x)
        {
            x = 100;

            printf("Thread %d sets x = %d\n",
                   omp_get_thread_num(), x);
        }

        printf("Thread %d sees x = %d\n",
               omp_get_thread_num(), x);
    }

    return 0;
}
