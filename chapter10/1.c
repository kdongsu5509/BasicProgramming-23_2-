/*에라토스테네스의 체*/
/*2의 배수 제거
3의 배수 제거
5의 배수 제거
7의 배수 제거
.........> n이 클수록 시간 복잡도가 감소한다.*/

/*전역 배열 선언 후 / 전부 0로 초기화 // 소수면 1로 // 1일 때 모든 배수 삭제(아래 참고)

초기화 -> for (int i = 2; i <= n, i++){
    if (sieve[i] == 1){
        for(int j = i+i; j<=n ; j++){
            sieve[j] == 0
        }
    }
}--> 시간 초과 뜸. 딱 보면 알지?

for(int i = 2 ; (int)sqrt(n); i++){
    if(sieve[i]==1){
        for(int j = i+i ; j <= n ; ){
            sieve[j] == 0
        }
    }
}
*/

#include <stdio.h>
#include <math.h>
#define MAX 1000000

int sieve[MAX + 1];

/* Fill the global variable sieve with 0 or 1.
   The value of sieve[i] should be 1 if i is prime,
   and 0 if i is not prime.
*/
void find_primes();

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    find_primes();
    int cnt = 0;
    for (int i = N; i <= M; i++)
        if (sieve[i])
            cnt++; // sieve[i]가 1이어야하네
    printf("%d", cnt);
}

void find_primes()
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

// 에라토스테네스의 체 구현 코드
// for (int i = 2; i <= sqrt(MAX); i++)
// {
//     if (sieve[i] == 1)
//     {
//         int temp = i;
//         int j = 2;
//         while (temp <= MAX)
//         {
//             temp *= j;
//             sieve[temp] = 0;
//             j = j + 1;
//         }
//     }
// }