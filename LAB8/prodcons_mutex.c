#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int myID;

pthread_mutex_t r_mutex, w_mutex;

void *print_message_function(void *arg)
{
    int *num = (int *)arg;
    myID = *num;
    int i;
    for (i = 0; i < *num; i++)
    {
        myID = rand() % *num;
        printf("writer wrote: %d\n", myID);
    }
    return NULL;
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    int i;
    int read = atoi(argv[1]);
    pthread_t threadID[1];
    pthread_mutex_init(&w_mutex, NULL);
    pthread_mutex_init(&r_mutex, NULL);
    pthread_create(&threadID[0], NULL, print_message_function, (void *)&read);
    if (read <= 0)
    {
        exit(EXIT_FAILURE);
    }
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    sleep(1);
    for (i = 0; i < read; i++)
    {
        pthread_mutex_lock(&r_mutex);
        printf("main read: %d\n", myID);
        pthread_mutex_unlock(&w_mutex);
    }
    pthread_join(threadID[0], NULL);
    exit(EXIT_SUCCESS);
}