#include <stdio.h>
#include <math.h>

typedef unsigned long long long_t;

/* returns the sum of factors*/
long_t sum_factors(long_t n);

int main()
{
    long_t n, m, maxcnt, maxval;
    scanf("%llu %llu", &n, &m);
    maxcnt = maxval = 0;
    // maxcnt = 소인수의 합
    // maxval = 가장 큰 수
    for (long_t i = n; i <= m; i++)
    {
        long_t s = sum_factors(i);
        if (s >= maxcnt)
        {
            maxcnt = s;
            maxval = i;
        }
    }
    printf("%llu\n", maxval); // 가장 큰 수
    printf("%llu", maxcnt);   // 소인수의 합 //factors의 출력
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

    if (sum == n)
    {
        return 0;
    }
    else
    {
        return sum;
    }
}