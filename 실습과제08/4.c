#include <stdio.h>
#include <math.h>

int is_prime(int n);
int prime_cnt(int N, int M);

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    printf("%d\n", prime_cnt(N, M));
}

int is_prime(unsigned int n)
{
    if (n <= 3)
        return 1;

    // 2를 제외한 짝수는 소수가 아님
    if (n % 2 == 0)
        return 0;

    // 3부터 sqrt(n)까지 홀수만 확인
    for (unsigned int i = 3; i <= (unsigned int)(sqrt(n)); i += 2)
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
        int cnt = 0;
        if (is_prime(x))
        {
            cnt++;
        }
    }
    return cnt;
}