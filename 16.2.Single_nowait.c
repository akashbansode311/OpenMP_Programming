#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            printf("Thread %d executes single block.\n",
                   omp_get_thread_num());
        }

        printf("Thread %d continues execution.\n",
               omp_get_thread_num());
    }

    return 0;
}
