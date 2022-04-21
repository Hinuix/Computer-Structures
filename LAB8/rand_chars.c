#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upperCase()
{
    printf("%c\n", rand() % 26 + 65);
}

void lowerCase()
{
    printf("%c\n", rand() % 26 + 97);
}

int main(int argc, char *argv[])
{
    (void)argc;
    char *chr = argv[1];
    int i;

    for (i = 0; i < 10; i++)
    {
        if (strcmp("-u", chr) == 0)
        {
            upperCase();
        }
        else if (strcmp("-l", chr) == 0)
        {
            lowerCase();
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
}