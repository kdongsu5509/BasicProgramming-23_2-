/*콜라츠의 추측*/
/*전역변수 쓰면 된다... 마지막에는 공백이 없어야 한다.*/

// 중간고사 // 1부터 100까지의 콜라츠 수열 중에서 가장 긴 혹은 길이가 짝수인 것의 개수는 혹은 중간에 17이 나타나는
// 콜라츠 수열의 개수는 등등으로 등장할 예정.

#include <stdio.h>

typedef unsigned long long long_t;

int cnt = 0;

void collatz(long_t n);

int main()
{
    int N;
    scanf("%d", &N);
    collatz(N);
    printf("\n%d", cnt);
}

void collatz(long_t n)
{
    if (n == 1)
    {
        printf("%llu", n);
        cnt++;
    }
    else if (n % 2 == 0)
    {
        printf("%llu ", n);
        cnt++;
        collatz(n / 2);
    }
    else
    {
        printf("%llu ", n);
        cnt++;
        collatz((n * 3) + 1);
    }
}