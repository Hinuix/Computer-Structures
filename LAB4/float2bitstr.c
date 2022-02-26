#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        printf("No input given\n");
        exit(1);
    }
    double num = (double)atof(argv[1]);

    long unsigned *n = (long unsigned *)(&num);

    int sign = (*n >> 63);
    int exponent = (*n << 1 >> 53) - 1023 + 127;
    int mantissa = (*n << 12 >> 41);

    printf("%d", sign);

    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (exponent & 1 << i) != 0);
    }

    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (mantissa & 1 << i) != 0);
    }

    printf("\n");
    return 0;
}