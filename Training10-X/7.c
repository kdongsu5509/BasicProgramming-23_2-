#include <stdio.h>
#include <math.h>

int is_palindrome(unsigned n);
int is_prime(unsigned n);

int main()
{
    unsigned N, M;
    scanf("%u %u", &N, &M);
    int cnt = 0;

    if (N < 2)
        N = 2;

    for (unsigned i = N; i <= M; i++)
    {
        if (is_palindrome(i) && is_prime(i))
            cnt++;
    }
    printf("%d\n", cnt);
}

int is_palindrome(unsigned n)
{
    int numBits = sizeof(n) * 8;
    int left = 0;
    int right = numBits - 1;

    while (left < right)
    {
        if (((n & (1 << left)) >> left) != ((n & (1 << right)) >> right))
        {
            return 0; // 이진수 팰린드롬이 아님
        }
        left++;
        right--;
    }

    return 1; // 이진수 팰린드롬임
}

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
