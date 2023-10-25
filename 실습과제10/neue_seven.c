#include <stdio.h>

int is_prime(unsigned n)
{
    if (n <= 1)
    {
        return 0; // 0과 1은 소수가 아닙니다.
    }
    if (n <= 3)
    {
        return 1; // 2와 3은 소수입니다.
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

int main()
{
    unsigned N, M;
    scanf("%u %u", &N, &M);
    int cnt = 0;

    for (unsigned i = N; i <= M; i++)
    {
        if (i % 2 != 0 && is_prime(i))
        {
            // 홀수만 고려하고, 소수인지 확인합니다.
            unsigned num = i;
            unsigned reversed = 0;
            while (num > 0)
            {
                reversed = reversed * 10 + num % 10;
                num /= 10;
            }
            if (reversed == i)
            {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
