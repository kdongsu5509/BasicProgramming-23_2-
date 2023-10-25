#include <stdio.h>
#include <math.h>

typedef unsigned long long ulong_t;
typedef unsigned int uint_t;

uint_t divcnt(uint_t n);
void solve(uint_t N, uint_t M);

int main()
{
    uint_t N, M;
    scanf("%u %u", &N, &M);
    solve(N, M);
}

uint_t divcnt(uint_t n) // 카운트 놈으로
{
    uint_t c = 0;
    if (n == 1)
    {
        c = 1;
        return c;
    }
    for (ulong_t x = 1; x * x <= n; x++)
    {
        if (x * x == n)
        {
            c += 1;
        }
        else
        {
            if (n % x == 0)
            {
                c += 2;
            }
        }
    }
    return c;
}

void solve(uint_t N, uint_t M)
{
    unsigned long long max_c = 0;
    unsigned long long max = 0;

    for (unsigned long long x = N; x <= M; x++)
    {
        uint_t c = divcnt(x);
        if (max_c <= c)
        {
            max_c = c;
            max = x;
        }
    }

    printf("%llu\n", max);
    printf("%llu\n", max_c);
}