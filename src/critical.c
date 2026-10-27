/* critical.c - Program 2: Critical section
 * Compile: gcc critical.c -fopenmp -o critical
 * Run:     OMP_NUM_THREADS=4 ./critical
 */
#include <stdio.h>
#include <omp.h>

int main() {
    long counter = 0;

    #pragma omp parallel for
    for (long i = 0; i < 10000000; i++) {
        #pragma omp critical
        { counter++; }             /* one thread at a time */
    }

    printf("Counter=%ld\n", counter);
    return 0;
}
