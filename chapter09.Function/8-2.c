#include <stdio.h>
#include <math.h>

// 약수의 개수가 가장 많은 수 출력 + 그 수의 약수 개수 출력

typedef unsigned long long ulong_t;
typedef unsigned int uint_t;

uint_t divcnt(uint_t n);
void solve(uint_t N, uint_t M);

int main()
{
    uint_t N, M;
    scanf("%u %u", &N, &M);
    solve(N, M);
}

void solve(uint_t N, uint_t M)
{

    uint_t max = 0;
    uint_t max_T = 0;

    for (uint_t t = N; t <= M; t++)
    {
        uint_t x = divcnt(t);

        if (max <= x)
        {
            max = x;
            max_T = t;
        }
    }

    printf("%u\n", max_T);
    printf("%u", max);
}

uint_t divcnt(uint_t n)
{

    uint_t sum = 1;
    uint_t cnt1 = 0;

    while (n % 2 == 0) /*받은 코드에서는 없는 부분1. ; 연산 횟수 증가 / */
    {
        n /= 2;
        cnt1++;
    }

    sum *= (cnt1 + 1);

    for (uint_t i = 3; i <= sqrt(n); i = i + 2) /*받은 코드에서는 2씩 증가가 아니라 1씩 증가
               -->sqrt(n)번 반복(받은 코드) / 해당 코드 : sqrt(n)/2 번 반복*/
    {
        uint_t count = 0;

        if (n % i == 0)
        {
            while (n % i == 0)
            {
                count++; /*받은 코드에서는 전위 연산(++count) 사용*/
                n /= i;  /*sqrt()를 사용하여 */
            }
        }

        if (count > 0) /*받은 코드에서는 없는 부분 2== if판별 ; for문의 반복만큼 연산 횟수 증가*/
        {
            sum *= (count + 1);
        }
    }

    if (n > 1)
    {
        sum *= 2;
    }

    return (sum);
}

/*
주어진 함수 divcnt는 양의 정수 n을 입력으로 받고, n의 약수의 개수를 계산하여 반환하는 함수입니다. 이 함수의 시간 복잡도를 분석하겠습니다.

while (n % 2 == 0) 루프:

이 루프는 n을 2로 나눌 수 있는만큼 계속해서 나눕니다. 이 때 cnt1을 증가시키고, 나누는 동작을 수행합니다.
이 루프의 시간 복잡도는 O(log₂(n))입니다. 최대로 2로 나눌 수 있는 횟수는 log₂(n)이기 때문입니다.
for 루프:

이 루프는 i를 3부터 시작하여 홀수로 2씩 증가시키면서 n을 나눌 수 있는지 확인하고 약수의 개수를 계산합니다.
이 루프는 i가 3부터 시작해서 sqrt(n)까지 반복하게 되므로, 시간 복잡도는 O(sqrt(n))입니다. 여기서 sqrt(n)은 n의 제곱근입니다.
마지막 if(n>1) 문:

이 부분은 남아 있는 n이 1보다 큰 경우에 두 배의 약수를 추가로 더합니다.
따라서 전체 함수의 시간 복잡도는 O(log₂(n) + sqrt(n))입니다. 이것은 n에 대해 로그 및 제곱근에 비례하는 시간이 걸리는 것을 의미합니다. 이 함수의 시간 복잡도는 n에 대해 상대적으로 빠르게 실행될 것으로 예상됩니다.*/

uint_t divcnt(uint_t n)
{

    uint_t cnt = 1;

    for (uint_t i = 2; i <= sqrt(n); ++i)
    {
        uint_t power = 0;
        while (n % i == 0)
        {
            n /= i;
            ++power;
        }
        cnt *= (power + 1);
    }
    if (n > 1)
    {
        cnt *= 2;
    }
    return cnt;
}