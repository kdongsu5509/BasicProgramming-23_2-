#include <stdio.h>
#include <math.h>

int is_prime(unsigned int n);
unsigned int solve(unsigned int N);

int p = 0;

int main()
{
    unsigned int N;
    scanf("%d", &N);

    printf("%X\n", solve(N));
}

int is_prime(unsigned int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (unsigned i = 3; i <= (unsigned int)(sqrt(n)); i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

unsigned int solve(unsigned int N)
{
    int k = 0;

    for (unsigned int i = 0; i < N; i++)
    {
        unsigned long long temp;
        scanf("%llu", &temp);
        if (is_prime(temp))
        {
            k |= (1 << (N - 1 - i));
        }
    }
    return k;
    // 숫자 다 넣음.
}