#include <stdio.h>

int ONE[10][10];
int TWO[10][10];
int THREE[10][10];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            int i;
            scanf("%d", &i);
            ONE[a][b] = i;
        }
    }
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            int i;
            scanf("%d", &i);
            TWO[a][b] = i;
        }
    }
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            int i;
            scanf("%d", &i);
            THREE[a][b] = i;
        }
    }
    /*입력 완료*/

    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            int p;
            p = ONE[a][b] + TWO[a][b] - THREE[a][b];
            if (b == M - 1)
            {
                printf("%d\n", p);
            }
            else
            {
                printf("%d ", p);
            }
        }
    }

    /*행렬의 덧셈
    값은 위치값(2차원 배열인 경우 행과 열)을 가진 놈들을 더하고 뺀다.*/

    return 0;
}