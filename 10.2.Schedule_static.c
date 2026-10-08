#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 10; i++) {
        printf("Static: i=%d thread=%d\n", i, omp_get_thread_num());
    }
    return 0;
}
