/*골드바흐

4보다 큰 모든 짝수는 두 개의 홀수인 소수의 합으로 나타낼 수 있다.

4보다 큰 짝수에 대해 소수 a,b 합으로 나타낼 수 있는 경우의 수



a의 오름차순 출력

경우의 수가 100보다 크면 경우의 수만 출력*/

#include <stdio.h>
#include <math.h>
#define MAX 1000000

int sieve[MAX + 1];

void find_primes(); // 완료
int count(int n);   // 완료
void solve(int n);  //

int main()
{
    int N;
    scanf("%d", &N);
    find_primes();
    int x = count(N);
    // printf("count is %d", x);
    solve(N);
}

/* Count the number of primes between 3 and n/2 */
int count(int n)
{
    int cnt = 0;
    for (int i = 3; i <= n / 2; i++)
    {
        if (sieve[i] && sieve[n - i])
            cnt++;
    }
    return cnt;
}

void solve(int n)
{
    int cnt = count(n); // 개수는 다 받았네?
    if (cnt < 100)
    {
        while (!(cnt == 0))
        {
            for (int i = 3; i <= n / 2; i++)
            {
                if (sieve[i] && sieve[n - i])
                {
                    if (!(cnt == 1))
                    {
                        printf("%d %d\n", i, n - i);
                        cnt--;
                    }
                    else
                    {
                        printf("%d %d", i, n - i);
                        cnt--;
                    }
                }
            }
        }
    }
    else
    {
        printf("%d", cnt);
    }
}

void find_primes() // 다 MAX로 해서 상관 ㄴㄴ
{
    // 초기화
    for (int i = 2; i <= MAX; i++)
    {
        sieve[i] = 1;
    }

    sieve[0] = 0;
    sieve[1] = 0; // 0하고 1은 소수가 아니므로 처리해줘야지

    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j <= MAX; j += i) // j += i는 좀 신박한 걸?
            {
                sieve[j] = 0;
            }
        }
    }
}