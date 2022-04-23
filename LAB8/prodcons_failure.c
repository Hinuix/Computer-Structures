#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int myID;

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
    pthread_create(&threadID[0], NULL, print_message_function, (void *)&read);
        if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    if (read < 1) {
      exit(EXIT_FAILURE);
    }
    for (i = 0; i < read; i++)
    {
        printf("main read: %d\n", myID);
    }
    pthread_join(threadID[0], NULL);
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}