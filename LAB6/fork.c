#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid;
    int i;
    i = atoi(argv[1]);
    pid = fork();

    printf("Hello World\n");

    if (pid == 0)
    {
        printf("Child: %d\n", --i);
    }

    else
    {
        printf("Parent: %d\n", ++i);
    }
    if (argc < 2)
    {
        exit(EXIT_FAILURE);
    }
}
