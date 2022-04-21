#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* printA()
{
    sem_wait(&mutex);
    printf("A\n");
    return(0);
}

void* printB()
{
    sem_wait(&mutex);
    printf("B\n");
    return(0);
}

void* printC()
{
    sem_wait(&mutex);
    printf("C\n");
    return(0);
}

int main(int argc, char *argv[])
{
    (void) argv[0];
    
    pthread_t tid[3];

    if(argc != 1){
        exit(EXIT_FAILURE);
    }

    sem_init(&mutex,0,2);
    
    pthread_create(&tid[0], NULL, printA, NULL);
    pthread_create(&tid[1], NULL, printB, NULL);
    pthread_create(&tid[2], NULL, printC, NULL);

    // FIX for code issue
    sem_post(&mutex);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);

    return(0);
}