#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void *create_thread(void *(*worker)(void *), void *data)
{
    pthread_t *thread = malloc(sizeof(pthread_t));
    pthread_create(thread, NULL, worker, data);

    return thread;
}

// void close_thread(void *th)
// {
//     pthread_t *thread = th;
//     pthread_cancel(*thread);
// }