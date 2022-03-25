#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int num[2];
    char stringOne[50];
    char stringTwo[50];

    if (pipe(num) < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (argc != 3)
    {
        exit(EXIT_FAILURE);
    }

// Second String
    write(num[1], argv[1], 50);
    read(num[0], stringOne, 50);
    printf("%s\n", stringOne);

// First String
    write(num[1], argv[2], 50);
    read(num[0], stringTwo, 50);
    printf("%s\n", stringTwo);
}