/* race.c - Program 1: Race condition (NO synchronization)
 * Compile: gcc race.c -fopenmp -o race
 * Run:     OMP_NUM_THREADS=4 ./race
 */
#include <stdio.h>
#include <omp.h>

int main() {
    long counter = 0;

    #pragma omp parallel for
    for (long i = 0; i < 10000000; i++)
        counter++;                 /* unprotected read-modify-write */

    printf("Counter=%ld\n", counter);
    return 0;
}
