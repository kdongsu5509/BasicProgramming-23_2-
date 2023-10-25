#include <stdio.h>

#define MAX 100

int square[MAX][MAX];
/*c언어에서 전역변수 및 정적 배열은 자동으로 0으로 초기화함.

전역 변수와 정적 배열은 데이터 세그먼트에 저장되는데
데이터 세그먼트에 저장된 데이터는 컴파일러 또는 런타임 시스템에 의해
자동으로 0으로 초기화 된다.*/

void magic(int n);

int main()
{
    int n;
    scanf("%d", &n);
    magic(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", square[i][j]);
        printf("\n");
    }
}

void magic(int n)
{
    int row = 0, column = n / 2;
    int next_row = row, next_column = n / 2;
    int full_number = n * n;
    int num = 1;

    square[row][column] = num;
    num++;

    for (; num <= full_number; num++)
    {
        next_row = (row - 1 + n) % n;
        next_column = (column + 1) % n;

        if (square[next_row][next_column] != 0)
        {
            next_row = (row + 1) % n;
            next_column = column;
        }

        square[next_row][next_column] = num;

        row = next_row;
        column = next_column;
    }
}
