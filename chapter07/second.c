#include <stdio.h>
typedef unsigned long long ull;

int main()
{
    ull N;
    scanf("%llu", &N);

    ull oneCount = 0;
    ull zeroCount = 0;

    while (N > 0)
    {
        if (N & 1)
        {
            oneCount++;
        }
        else
        {
            zeroCount++;
        }

        N = N >> 1;
    }

    printf("%llu\n", oneCount);
    printf("%llu", zeroCount);

    return 0;
}