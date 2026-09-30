#include <stdio.h>
#include <omp.h>

int main()
{
    int N = 10;

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < N; i++)
            {
                #pragma omp task
                {
                    printf("Task %d executed by thread %d\n",
                           i, omp_get_thread_num());
                }
            }
        }
    }

    return 0;
}
