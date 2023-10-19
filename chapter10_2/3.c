// a의 b승 -> a를 b번 곱하면 ㅆㄱㄴ

// 행렬의 거듭제곱은???
/*재귀를 사용해야 효율적이다


지수가 홀/짝 으로 경우 나누기

지수가 짝 --> 지수/2 * 지수/2

지수가 홀 --> 지수/2 * 지수/2 * 밑(1개)
    ->이래되뿌면 짝수가 된다잉


공통 == b가1일떄 , 혹은 a의 b승이 a가 될 때(똑같은 말이긴 해 ㅋㅋ)
*/

#include <stdio.h>

typedef long long lont_t;

/* muliplies two matrices A and B into a matrix C */
void mult(lont_t A[][2], lont_t B[][2], lont_t C[][2]);

/* powers a matrix A with exponent n into a matrix B */
void power(int n, lont_t A[][2], lont_t B[][2]);

int main()
{
    int n;
    scanf("%d", &n);
    lont_t A[2][2], B[2][2];
    scanf("%lld %lld %lld %lld", &A[0][0], &A[0][1], &A[1][0], &A[1][1]);
    power(n, A, B);
    printf("%lld %lld \n%lld %lld ", B[0][0], B[0][1], B[1][0], B[1][1]);
}

void mult(lont_t A[][2], lont_t B[][2], lont_t C[][2])
{
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

void power(int n, lont_t A[][2], lont_t B[][2])
{
    if (n == 0)
    {
        B[0][0] = 1;
        B[0][1] = 0;
        B[1][0] = 0;
        B[1][1] = 1;
        return;
    }

    long long temp[2][2];
    power(n / 2, A, temp);
    mult(temp, temp, B);

    if (n % 2 == 1)
    {
        long long temp2[2][2];
        mult(A, B, temp2);
        B[0][0] = temp2[0][0];
        B[0][1] = temp2[0][1];
        B[1][0] = temp2[1][0];
        B[1][1] = temp2[1][1];
    }
}

// void mult(lont_t A[][2], lont_t B[][2], lont_t C[][2])
// {
//     // x는 행 y는 열
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < p; j++)
//         {
//             C[i][j] = 0;
//             for (int k = 0; k < n; k++)
//             {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
// }

// void power(int n, lont_t A[][2], lont_t B[][2])
// {
//     // 아마 여기에 multiple넣어야함
//     if (n == 1)
//     {
//         B[0][0] = 1;
//         B[0][1] = 0;
//         B[1][0] = 0;
//         B[1][1] = 1;
//     }
//     else if (n % 2 == 0)
//     {
//         power(n / 2, A, B);
//     }
//     else
//     {
//         multi(power(n / 2, A, B), A)
//     }
// }
