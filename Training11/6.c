/*회전 행렬

rotate()만 구하기*/
#include <stdio.h>
#define MAX 100

/* rotates the matix A into the matrix B. */
void rotate(int n, int A[][MAX], int B[][MAX]);

int main()
{
    int n, A[MAX][MAX], B[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    rotate(n, A, B);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
}

void rotate(int n, int A[][MAX], int B[][MAX])
{
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            // if (n - x - 1 < 0)
            // {
            //     x = n - 1;
            //     B[y][n - x - 1] = A[x][y];
            // }
            // else
            // {
            //     B[y][n - x - 1] = A[x][y];
            // }
            B[y][n - x - 1] = A[x][y];
        }
    }
}