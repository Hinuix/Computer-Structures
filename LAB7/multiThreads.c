#define _POSIX_C_SOURCE 200809L
#define NTHREADS 1000
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef struct inputs arguments;

struct inputs
{
    char *firstWord;
    char *secondWord;
};

void *file_read(void *arg)
{
    arguments *args = (arguments *)arg;
    FILE *file;
    char *buffer = NULL;
    char *temporay = NULL;
    size_t bufferSize = 0;
    ssize_t characters;
    int wordCount = 0;

    file = fopen(args->firstWord, "r");
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while ((characters = getline(&buffer, &bufferSize, file) != -1))
    {
        temporay = buffer;
        while ((temporay = strstr(temporay, args->secondWord)) != NULL)
        {
            wordCount += 1;
            *temporay = *temporay + strlen(args->secondWord);
        }
    }
    fclose(file);
    printf("%s Count: %d\n", args->secondWord, wordCount);
    return NULL;
}

int main(int argc, char *argv[])
{
    (void)argc;
    arguments fileName = {.firstWord = argv[1], .secondWord = argv[2]};
    arguments word = {.firstWord = argv[3], .secondWord = argv[4]};
    pthread_t treadID[NTHREADS];
    pthread_create(&treadID[0], NULL, file_read, (void *)&fileName);
    pthread_create(&treadID[1], NULL, file_read, (void *)&word);
    pthread_join(treadID[0], NULL);
    pthread_join(treadID[1], NULL);
}