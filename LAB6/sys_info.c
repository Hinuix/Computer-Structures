#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int num[2];
    int end;
    char firstNum[50];
    char bin[50] = "/bin/";
    char secondNum[50];
    char *ch;

    if (pipe(num) < 0)
    {
        printf("too few arguments\n");
    }

    if (argc > 3)
    {
        printf("too many arguments\n");
    }

    int i = fork();
    if (i < 0)
    {
        printf("failure in fork\n");
    }
    else if (i > 0)
    {
        write(num[1], argv[1], 50);
        write(num[1], argv[2], 50);

        wait(&end);
        close(num[0]);
        close(num[1]);
        if (end != 0)
        {
            printf("failure in creating pipe\n");
        }
    }
    else
    {
        read(num[0], firstNum, 50);
        read(num[0], secondNum, 50);
        if ((ch = strstr(firstNum, "/bin/")) == (void *)0)
        {
            strcat(bin, firstNum);
            if (execl(bin, firstNum, secondNum, NULL) != 0)
            {
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (execl(firstNum, firstNum + 5, secondNum, NULL) != 0)
            {
                printf("incorrect argument passed to execl()");
            }
        }
    }
}