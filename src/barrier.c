/* barrier.c - Program 4: Barrier
 * Compile: gcc barrier.c -fopenmp -o barrier
 * Run:     OMP_NUM_THREADS=8 ./barrier
 */
#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        printf("Thread %d before barrier\n", omp_get_thread_num());

        #pragma omp barrier        /* nobody passes until all threads arrive */

        printf("Thread %d after barrier\n", omp_get_thread_num());
    }
    return 0;
}
