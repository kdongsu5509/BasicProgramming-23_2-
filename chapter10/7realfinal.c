#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_palindrome(unsigned n)
{
    unsigned long long original = n;
    unsigned long long reversed = 0;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}

bool is_prime(unsigned n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (unsigned long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    unsigned N, M;
    scanf("%u %u", &N, &M);
    int cnt = 0;

    for (unsigned long long i = N; i <= M; i++)
    {
        if (is_palindrome(i) && is_prime(i))
        {
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}

/// VS깔자... / 디버깅 굳굳

// 오버리밋으로 인해 문제가 해결되지 않았었음..
// 자료형 무조건 unsigned long long으로 할끼다.