#include <stdio.h>
#include <math.h>
#define MAX 32

/*
 * The function factorize() factorizes n
 * and store the fequency of factors in the array a[],
 * which is passed by the caller as an argument.
 */
unsigned factorize(unsigned n, unsigned a[]);

int main()
{
    unsigned N, a[MAX];
    scanf("%u", &N);
    unsigned len = factorize(N, a);
    unsigned p = a[0], cnt = 0;
    for (unsigned i = 0; i < len; i++)
    {
        if (p == a[i])
        {
            cnt++;
        }
        else
        {
            printf("%u %u\n", p, cnt);
            p = a[i];
            cnt = 1;
        }
    }
    printf("%u %u\n", p, cnt);
}

unsigned factorize(unsigned n, unsigned a[])
{
    // len은 소인수 전체의 개수이다.
    unsigned cnt = 0;

    for (unsigned i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while ((n % i) == 0)
            {
                n /= i;
                a[cnt] = i;
                cnt += 1;
            }
        }
    }

    if (n > 1)
    {
        a[cnt] = n;
        cnt += 1;
    }

    return cnt;
}