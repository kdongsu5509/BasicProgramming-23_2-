#include <stdio.h>

#define MAX 100

int N, A[MAX][MAX];

/* make a counter-clockwise spiral matrix into the N*N matrix A */
void make_spiral();

int main()
{
    scanf("%d", &N);
    make_counter_clockwise_spiral();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void make_spiral()
{
    int in_num = 1;
    int top = 0, bottom = N - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right)
    {
        // 위에서 아래로
        for (int i = top; i <= bottom; i++)
        {
            A[i][left] = in_num++;
        }
        left++;

        for (int i = left; i <= right; i++)
        {
            A[bottom][i] = in_num++;
        }
        bottom--;

        // 밑에서 위로
        for (int i = bottom; i >= top; i--)
        {
            A[i][right] = in_num++;
        }
        right--;

        // 왼쪽으로...
        for (int i = right; i >= left; i--)
        {
            A[top][i] = in_num++;
        }
        top++;

        //
    }
}
