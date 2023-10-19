#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];

int main()
{
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);

    /*A받기*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    /*B받기*/
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    /*C를 초기화?? 함.*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C[i][j] = 0;
        }
    }

    /*곱하기*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    /*출력부분*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j == M - 1)
            {
                printf("%d\n", C[i][j]);
            }
            else
            {
                printf("%d ", C[i][j]);
            }
        }
    }

    return 0;
}