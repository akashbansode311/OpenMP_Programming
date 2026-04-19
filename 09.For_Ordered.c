#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    printf("Parallel loop with ordered output:\n");

    #pragma omp parallel for ordered
    for(int i = 0; i < 4; i++)
    {
        #pragma omp ordered
        {
            // This part runs in sequence (0 - 4)
            printf("Thread %d processes iteration %d\n", omp_get_thread_num(), i);
        }
    }
return 0;
}
