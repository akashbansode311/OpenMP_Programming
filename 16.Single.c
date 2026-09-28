#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        printf("Thread %d is working.\n",
               omp_get_thread_num());

        #pragma omp single
        {
            printf("Thread %d executes the single block.\n",
                   omp_get_thread_num());
        }

        printf("Thread %d continues working.\n",
               omp_get_thread_num());
    }

    return 0;
}
