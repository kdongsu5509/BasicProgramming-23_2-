#include <stdio.h>
#include <math.h>

typedef unsigned long long ull_t;

ull_t divsum(ull_t n);

int main()
{
    ull_t N;
    scanf("%llu", &N);
    printf("%llu", divsum(N));
}

ull_t divsum(ull_t n)
{
    ull_t sum = 0;
    if (n == 1)
    {
        sum = 1;
        return sum;
    }
    for (ull_t i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            sum = sum + i;
        }
        else
        {
            if (n % i == 0)
            {
                sum = sum + (n / i) + i;
            }
        }
    }
    return sum;
}