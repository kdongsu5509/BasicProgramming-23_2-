#include <stdio.h>
#define SIZE 10

int *mmmax(int n, int m, int p, int *ptr, int *a, int *b, int *c);

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int A[SIZE][SIZE][SIZE]; //아직 malloc, alloc등을 안배워서 (메모리 자동 할당) -> 먼저 큰 사이즈를 선언 => 배열 계산 시 유의할 점.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                scanf("%d", &A[i][j][k]);
    int i, j, k;
    int *maxptr = mmmax(n, m, p, &A[0][0][0], &i, &j, &k);
    printf("%d %d %d %d %d", *maxptr, A[i][j][k], i, j, k);
}

int *mmmax(int n, int m, int p, int *ptr, int *a, int *b, int *c)
{
    int max = *ptr;
    int *maxptr = ptr;
    *a = 0;
    *b = 0;
    *c = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                if (*(ptr + i * SIZE * SIZE + j * SIZE + k) > max) // 배열이 SIZE로 선언되서 SIZE만큼 뛰어넘어야 됨.(포인터를 사용시)
                {
                    max = *(ptr + i * SIZE * SIZE + j * SIZE + k);
                    maxptr = (ptr + i * SIZE * SIZE + j * SIZE + k);
                    *a = i;
                    *b = j;
                    *c = k;
                }
            }
        }
    }

    return maxptr;
}