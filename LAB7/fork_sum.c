#ifndef ASIZE
#define ASIZE 1000
#endif
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    (void)argc;
    int array[ASIZE];

    int i;
    for (i = 0; i < ASIZE; i++)
    {
        array[i] = i * atoi(argv[1]);
    }

    int arraySum = 0;
    int forkSum[2];

    if (pipe(forkSum) < 0)
    {
        exit(EXIT_FAILURE);
    }
    int threadID = fork();
    if (threadID > 0)
    {
        for (i = 0; i < ASIZE / 2; i++)
        {
            arraySum += array[i];
        }
        write(forkSum[1], &arraySum, sizeof(arraySum));
        int q;
        wait(&q);
        close(forkSum[1]);
        close(forkSum[0]);
    }
    else if (threadID == 0)
    {
        read(forkSum[0], &arraySum, sizeof(arraySum));
        for (i = ASIZE / 2; i < ASIZE; i++)
        {
            arraySum += array[i];
        }
        printf("%d\n", arraySum);
    }
}