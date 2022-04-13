#define NTHREADS 2
#ifndef INCCNT
#define INCCNT 1000
#endif

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

void *concat(void *arg)
{
    char *temp = (char *)arg;
    printf("Concat String: %s Example\n", temp);
    return NULL;
}

void *count(void *arg)
{
    int *temp = (int *)arg;
    printf("Count: %d\n", *temp + INCCNT);
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        exit(EXIT_FAILURE);
    }
    pthread_t tid[NTHREADS];
    int two = atoi(argv[2]);
    pthread_create(&tid[1], NULL, count, (void *)&two);
    pthread_join(tid[1], NULL);
    pthread_create(&tid[0], NULL, concat, (void *)argv[1]);
    pthread_join(tid[0], NULL);

    exit(EXIT_SUCCESS);


}
