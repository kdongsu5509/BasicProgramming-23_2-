#include <stdio.h>

int main()
{
    unsigned long long num;
    scanf("%llu", &num);

    if (num == 0)
    {
        printf("0\n");
        return 0;
    }

    int leadingZeros = 1;
    while (num > 0)
    {
        unsigned long long digit = num % 10;
        if (digit != 0)
        {
            leadingZeros = 0;
        }
        if (!leadingZeros)
        {
            printf("%llu", digit);
        }
        num /= 10;
    }

    return 0;
}