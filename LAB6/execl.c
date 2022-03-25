#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char input[50] = "/bin/";
    strcat(input, argv[1]);
    execl(input, argv[1], argv[2], NULL);
    if (argc > 3)
    {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}