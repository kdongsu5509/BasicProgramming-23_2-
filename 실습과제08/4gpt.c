#include <stdio.h>
#include <math.h>

int is_prime(unsigned int n);
int prime_cnt(int N, int M);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d\n", prime_cnt(N, M));
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

int prime_cnt(int N, int M)
{
    int cnt = 0;
    for (int x = N; x <= M; x++)
    {
        if (is_prime(x))
        {
            cnt++;
        }
    }
    return cnt;
}