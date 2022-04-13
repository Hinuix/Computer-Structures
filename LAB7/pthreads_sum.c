#ifndef ASIZE
#define ASIZE 1000
#endif
#ifndef NTHREADS
#define NTHREADS 2
#endif
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
typedef struct array arr;

int arraySum = 0;
int array[ASIZE];

struct array
{
    int head;
    int tail;
};

void *arraySize(void *arg)
{
    arr *args = (arr *)arg;
    int i;
    for (i = args->head; i < args->tail; i++)
    {
        arraySum += array[i];
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    (void)argc;
    int i;
    for (i = 0; i < ASIZE; i++)
    {
        array[i] = i * atoi(argv[1]);
    }

    pthread_t threadID[NTHREADS];
    arr thread[NTHREADS];
    for (i = 0; i < NTHREADS; i++)
    {
        thread[i].head = (ASIZE * i) / NTHREADS;
        thread[i].tail = (ASIZE * (i + 1)) / NTHREADS;
        pthread_create(&threadID[i], NULL, arraySize, (void *)&thread[i]);
    }
    for (i = 0; i < NTHREADS; i++)
    {
        pthread_join(threadID[i], NULL);
    }
    printf("%d\n", arraySum);
}