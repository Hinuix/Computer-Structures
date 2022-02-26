#include <stdio.h>
#include <stdlib.h>

unsigned int float2bitstr(char *bin, int l, int r)
{
    unsigned int num = 0;
    for (int i = l; i <= r; i++)
    {
        if (bin[i] != '0' && bin[i] != '1')
        {
            printf("No input given\n");
            exit(0);
        }
        num = num * 2 + bin[i] - '0';
    }
    return num;
    exit(1);
}

typedef union
{
    float f;
    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } raw;
} myfloat;

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("No input given\n");
        return 1;
        exit(1);
    }

    myfloat var;
    var.raw.sign = 0;
    var.raw.exponent = 127;

    var.raw.mantissa = float2bitstr(argv[1], 9, 31);

    unsigned int exponent = float2bitstr(argv[1], 1, 8);

    unsigned int sign = argv[1][0] - '0';

    printf("Sign: %u\n", sign);
    printf("Exponent: %u\n", exponent);
    printf("Mantissa: %.17g\n", var.f);

    var.raw.sign = sign;
    var.raw.exponent = exponent;

    printf("Number: %.7g\n", var.f);

    return 1;
    exit(1);
}