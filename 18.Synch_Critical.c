#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    int total = 0;

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        // Each thread wants to add its ID to total
        #pragma omp critical
        {
             printf("Thread %d adding its value. Total before = %d\n", id, total);

             total = total + id;

             printf("Thread %d updated total to %d\n", id, total);
        }
    }
         printf("Final total = %d\n", total);
         return 0;
}
