#include <stdio.h>
#include <math.h>

int is_palindrome(unsigned n);
int is_prime(unsigned n);

int main()
{
    unsigned N, M, size;
    scanf("%u %u", &N, &M);
    int cnt = 0;

    // Ensure N is at least 2, as 0 and 1 are not prime.
    if (N < 2)
    {
        N = 2;
    }

    for (unsigned i = N; i <= M; i++)
    {
        if (is_palindrome(i))
        {
            if (is_prime(i))
            {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

int is_palindrome(unsigned n)
{
    int original = n;
    int reversed = 0;

    while (n > 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}

int is_prime(unsigned n)
{
    unsigned count = 0;

    if (n <= 1)
    {
        return 0; // 0과 1은 소수가 아닙니다.
    }

    if (n <= 3)
    {
        return 1; // 2와 3은 소수입니다.
        count++;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0; // 2 또는 3으로 나누어 떨어지면 소수가 아닙니다.
    }

    for (unsigned i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0; // 6k ± 1 형태의 숫자로 나누어 떨어지면 소수가 아닙니다.
        }
    }

    return 1; // 위의 조건을 만족하지 않으면 소수입니다.
}