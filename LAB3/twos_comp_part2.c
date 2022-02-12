#include <stdio.h>
#include <string.h>

int twos_comp_part2(const char *bin, int signedNum)
{
    int resolution = 0;
    int negativeNum = signedNum && bin[0] == '1';

    for (int i = 0; i < 8; i++)
    {
        if (negativeNum)
        {
            resolution = resolution * 2 + ((bin[i] - '0' + 1) % 2);
        }
        else
        {
            resolution = resolution * 2 + bin[i] - '0';
        }
    }
    if (negativeNum)
    {
        resolution = (resolution + 1) * -1;
    }
    return resolution;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        return 1;
    }
    int signedNum;
    if (strcmp(argv[2], "signed") == 0)
    {
        signedNum = 1;
    }
    else if (strcmp(argv[2], "unsigned") == 0)
    {
        signedNum = 0;
    }
    else
    {
        return 1;
    }
    if (strlen(argv[1]) != 8)
    {
        return 1;
    }
    printf("%d\n", twos_comp_part2(argv[1], signedNum));
    return 0;
}