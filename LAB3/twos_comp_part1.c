#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int input = atoi(argv[1]);
    (void)argc;

    char string[8] = "00000000";
    int j = 7;

    int number = abs(input);
    while (number)
    {
        int value = number % 2;
        string[j--] = (char)(value + '0');
        number = number / 2;
    }

    if (input >= 0)
    {
        for (int i = 0; i < 8; i++)
            printf("%c", string[i]);
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (string[i] == '0')
                string[i] = '1';
            else
                string[i] = '0';
        }
        for (int i = 7; i >= 0; i--)
        {
            if (string[i] == '0')
            {
                string[i] = '1';
                break;
            }
            else
            {
                string[i] = '0';
            }
        }

        for (int i = 0; i < 8; i++)
            printf("%c", string[i]"\n");
    }
}