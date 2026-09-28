#include <stdio.h>
#include <omp.h>

int main()
{
        omp_set_num_threads(2);
        #pragma omp parallel
        {
                #pragma omp master
                {
                        printf("MAster Thread = %d\n", omp_get_thread_num());
                }
                printf("Thread %d is working\n", omp_get_thread_num());
        }
        return 0;
}
