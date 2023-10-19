// 마방진 확인하기

/*idea 1

사이즈 확인 ->
마방진 만들어서 하나하나 위치에 따라 같은 값이 있는 지 비교하기
*/

/*idea 2

마법상수 구하기 = ((n*n+1)*n)/2

*/

#include <stdio.h>

#define MAX 100

int compArray[MAX][MAX];

int check(int n);

int main()
{
    int N;
    scanf("%d", &N);
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int temp;
            scanf("%d", &temp);
            compArray[x][y] = temp;
        }
    }

    int key = check(N);
    // printf("%s", "that is magic-----------------//");
    // for (int x = 0; x < N; x++)
    // {
    //     for (int y = 0; y < N; y++)
    //     {

    //         printf("%d", compArray[x][y]);
    //     }
    // }

    if (key)
    {
        printf("%d", ((N * N + 1) * N) / 2);
    }
    else
    {
        printf("%d", 0);
    }
}

int check(int n)
{
    int row = 0, col = n / 2;
    int num = 1;
    int maxNum = n * n;

    for (; num <= maxNum; num++)
    {
        if (compArray[row][col] != num)
        {
            return 0;
        }
        else if (compArray[row][col] == num)
        {
            compArray[row][col] = num * -1;
        }

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (compArray[nextRow][nextCol] < 0)
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
