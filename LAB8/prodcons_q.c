#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

char array[5];
pthread_mutex_t readMutex;
sem_t semaphoresOne, semaphoresTwo;
int threadOne, threadTwo;

void *lowerCase(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&semaphoresOne);
		pthread_mutex_lock(&readMutex);
		array[threadOne] = rand() % 26 + 97;
		printf("writer ID: %d, char written: %c\n", *id, array[threadOne]);
		threadOne = (threadOne + 1) % 5;
		pthread_mutex_unlock(&readMutex);
		sem_post(&semaphoresTwo);
	}
	return(0);
}

void *upperCase(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&semaphoresOne);
		pthread_mutex_lock(&readMutex);
		array[threadOne] = rand() % 26 + 65;
		printf("writer ID: %d, char written: %c\n", *id, array[threadOne]);
		threadOne = (threadOne + 1) % 5;
		pthread_mutex_unlock(&readMutex);
		sem_post(&semaphoresTwo);
	}
	return(0);
}

void *readingbuffer(void* arg){
	int* id = (int*) arg;
	int i;
	for(i = 0; i < 5; i++){
		sem_wait(&semaphoresTwo);
		pthread_mutex_lock(&readMutex);
		printf("reader ID: %d, char read: %c\n", *id, array[threadTwo]);
		threadTwo = (threadTwo + 1) % 5;
		pthread_mutex_unlock(&readMutex);
		sem_post(&semaphoresOne);
	}
	return(0);
}

int main(int argc, char* argv[]){
    (void)argv[0];
    
    int functionZero = 0;
	int functionOne = 1;
	int functionTwo = 2;
	int functionThree = 3;

	if(argc != 1){
		exit(EXIT_FAILURE);
	}
	sem_init(&semaphoresOne, 1, 5);
	sem_init(&semaphoresTwo, 1, 0);
	pthread_mutex_init(&readMutex, NULL);

	pthread_t threadID[8];
	threadOne = 0;
	threadTwo = 0;

	pthread_create(&threadID[0], NULL, lowerCase, (void*) &functionZero);
	pthread_create(&threadID[1], NULL, lowerCase, (void*) &functionOne);
	pthread_create(&threadID[2], NULL, upperCase, (void*) &functionTwo);
	pthread_create(&threadID[3], NULL, upperCase, (void*) &functionThree);
	pthread_create(&threadID[4], NULL, readingbuffer, (void*) &functionZero);
	pthread_create(&threadID[5], NULL, readingbuffer, (void*) &functionOne);
	pthread_create(&threadID[6], NULL, readingbuffer, (void*) &functionTwo);
	pthread_create(&threadID[7], NULL, readingbuffer, (void*) &functionThree);
	int i ;
	for(i = 0; i < 8; i++){
		pthread_join(threadID[i], NULL);
	}
	exit(EXIT_SUCCESS);
}