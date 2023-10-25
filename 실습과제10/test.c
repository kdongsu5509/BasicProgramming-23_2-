#include <stdio.h>
#include <math.h>

typedef unsigned long long long_t;

long_t sum_factors(long_t n);

int main()
{
    long_t N = 0;
    scanf("%u", &N);
    long_t k = sum_factors(N);
    printf("%u", k);
}

long_t sum_factors(long_t n)
{
    long_t sum = 0;

    for (long_t i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while ((n % i) == 0)
            {
                n /= i;
                sum += i;
            }
        }
    }

    if (n > 1)
    {
        sum += n;
    }

    return sum;
}