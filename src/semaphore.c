/* semaphore.c - Program 5: Binary semaphore (POSIX threads)
 * Compile: gcc semaphore.c -pthread -o semaphore
 * Run:     ./semaphore
 * Note: this uses pthreads (2 fixed threads), so OMP_NUM_THREADS has no effect.
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;
int counter = 0;

void* work(void* a) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&semaphore);      /* P(): decrement / block if 0 */
        counter++;
        sem_post(&semaphore);      /* V(): increment / release   */
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&semaphore, 0, 1);    /* initial value 1 => binary semaphore */

    pthread_create(&t1, NULL, work, NULL);
    pthread_create(&t2, NULL, work, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter=%d\n", counter);
    sem_destroy(&semaphore);
    return 0;
}
