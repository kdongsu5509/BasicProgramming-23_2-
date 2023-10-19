#include <stdio.h>
#include <math.h>

int is_prime(unsigned int n);

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 1)
        printf("not prime");
    else if (is_prime(N))
        printf("prime");
    else
        printf("composite");
}

int is_prime(unsigned int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;

    // 2를 제외한 짝수는 소수가 아님
    if (n % 2 == 0)
        return 0;

    // 3부터 sqrt(n)까지 홀수만 확인
    for (unsigned int i = 3; i <= (int)(sqrt(n)); i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
