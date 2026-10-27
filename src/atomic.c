/* atomic.c - Program 3: Atomic operation
 * Compile: gcc atomic.c -fopenmp -o atomic
 * Run:     OMP_NUM_THREADS=4 ./atomic
 */
#include <stdio.h>
#include <omp.h>

int main() {
    long counter = 0;

    #pragma omp parallel for
    for (long i = 0; i < 10000000; i++) {
        #pragma omp atomic
        counter++;                 /* hardware-level indivisible update */
    }

    printf("Counter=%ld\n", counter);
    return 0;
}
