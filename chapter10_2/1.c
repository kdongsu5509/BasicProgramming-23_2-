#include <stdio.h>

#define MAX 100

int square[MAX][MAX];

/* Make n * n magic square in a 2-dimensional array, square[].
 * It is guaranteed that n is always odd.
 */
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
