#include <stdio.h>
#define SZ 10


float A[SZ][SZ];

int main()
{
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
            A[i][j] = i * j;
    }

    for (int i = 0; i < SZ; i++)
    {
        for (int j = 1; j < SZ; j++){
            A[i][j] = (A[i][j - 1] + A[i][j]) / 2;
        printf("%f ", A[i][j]);
        printf("\n");
        }
    }

    return 0;
}
