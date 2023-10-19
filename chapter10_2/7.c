/*7번 문제는 이 파일 보지 말고, perfect7.c 보고 공부할 것.*/

// /*정방행렬을 나선행렬로

// ->방향은 반시계 방향
// make_spiral()함수 제작*/

// #include <stdio.h>
// #define MAX 100

// int N, A[MAX][MAX];

// /* make a spiral matrix into the N*N matrix A */
// void make_spiral();

// int main()
// {
//     scanf("%d", &N);
//     make_spiral();
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//             printf("%d ", A[i][j]);
//         printf("\n");
//     }
// }

// // void make_spiral()
// // {
// //     unsigned long long temp, cnt, i = 0;
// //     temp = N * N;
// //     cnt = 1;
// //     int row = -1;
// //     int column = 0;
// //     while (temp > cnt)
// //     {
// //         for (int a = 0; a < N - i; a++)
// //         {
// //             ++row;
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         for (int a = 0; a < N - i; a++)
// //         {
// //             ++column;
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         for (int a = 0; a < N - i; a++)
// //         {
// //             --row;
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         for (int a = 0; a < N - i; a++)
// //         {
// //             --column;
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         i++;
// //     }
// // }

// // void make_spiral()
// // {
// //     unsigned long long temp, cnt;
// //     temp = N * N;
// //     cnt = 1;
// //     int row = 0;
// //     int column = 0;
// //     int i = 0;

// //     while (cnt <= temp)
// //     {
// //         for (; row <= N - i; row++)
// //         {
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         column++;

// //         // 오른쪽으로 가자
// //         for (; column <= N - i; column++)
// //         {
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         column--;

// //         // 다시 위로~
// //         for (; row >= i; row--)
// //         {
// //             A[row][column] = cnt;
// //             cnt++;
// //         }
// //         row++;

// //         // 마지막 왼쪽
// //         for (; column >= i + 1; column--)
// //         {

// //             A[row][column] = cnt;
// //             cnt++;
// //         }

// //         column++;
// //         i++;
// //         row++;
// //         column++;
// //     }
// // }

// void make_spiral()
// {
//     unsigned long long temp, cnt;
//     temp = N * N;
//     cnt = 1;
//     int row = 0;
//     int column = 0;
//     int i = 0;

//     while (cnt <= temp)
//     {
//         // 오른쪽으로 이동
//         for (; column < N - i; column++)
//         {
//             A[row][column] = cnt;
//             cnt++;
//         }
//         column--; // column 값을 다시 돌려놓습니다.

//         // 아래로 이동
//         for (; row < N - i; row++)
//         {
//             A[row][column] = cnt;
//             cnt++;
//         }
//         row--; // row 값을 다시 돌려놓습니다.

//         // 왼쪽으로 이동
//         for (; column >= i; column--)
//         {
//             A[row][column] = cnt;
//             cnt++;
//         }
//         column++; // column 값을 다시 돌려놓습니다.

//         // 위로 이동
//         for (; row > i; row--)
//         {
//             A[row][column] = cnt;
//             cnt++;
//         }

//         // 한 바퀴를 완료했으므로 반지름 증가 및 시작 위치 조정
//         i++;
//         row++;
//         column++;
//     }
// }

#include <stdio.h>
#define MAX 100

int N, A[MAX][MAX];

/* make a spiral matrix into the N*N matrix A */
void make_spiral();

int main()
{
    scanf("%d", &N);
    make_spiral();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void make_spiral()
{
    // N과 2차원 배열 A는 전역변수로 선언된 친구들임.
    int arraySize = N * N;
    int num = 1;
    int r = 0;
    int c = 0;
    int pivot_point = 0;

    while (num <= arraySize)
    {
        // 아래로
        int down = 0;
        while (down < N - i)
        {
        }

        // 오른쪽으로
        for (; c < N; c++)
        {
            A[r][c] = num;
            num++;
        }
    }
}
