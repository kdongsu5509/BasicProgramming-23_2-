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

// void magic(int n)
// {
//     int maximum = n * n;
//     int cnt = 1;
//     int row = 0, column = 0;

//     // array init
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             square[i][j] = 0;
//         }
//     }

//     // positioning of number 1 at square
//     column = n / 2;
//     square[row][column] = cnt;

//     // start another number inputing
//     while (cnt <= maximum + 1)
//     {
//         // 위치 잡아주기
//         --row;
//         ++column;
//         if (row < 0)
//         {
//             row = n - 1;
//         }
//         if (column == (n - 1))
//         {
//             column = 0;
//         }
//         if (square[row][column] == 0)
//         {
//             square[row][column] = cnt;
//             cnt++;
//         }
//         else if (square[row][column] != 0)
//         {
//             --row;
//             square[row][column] = cnt;
//             cnt++;
//         }
//     }
// }

void magic(int n)
{
    int row = 0, col = n / 2;
    int num = 1;
    int maxNum = n * n;

    for (; num <= maxNum; num++)
    {
        square[row][col] = num;

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (square[nextRow][nextCol] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = nextRow;
            col = nextCol;
        }
    }
}
