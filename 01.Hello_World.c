#include<stdio.h>
//OpenMP Header File
#include<omp.h>
int main()
{
    //Set the Number of Threads i.e. 5
    omp_set_num_threads(5);
    //Parallel Region starts threads are spawned
    #pragma omp parallel
    //Statement Prints Five Times
    printf("Hello I am Thread %d\n",omp_get_thread_num());
    return 0;
}
//To Compile and run:
//$gcc -fopenmp filename.c -o filename
//$./filename
