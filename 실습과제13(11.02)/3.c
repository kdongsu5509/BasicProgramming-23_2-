#include <stdio.h>
#define SIZE 10

int *mmmax(int n, int m, int p, int *ptr, int *a, int *b, int *c);

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int A[SIZE][SIZE][SIZE]; //���� malloc, alloc���� �ȹ���� (�޸� �ڵ� �Ҵ�) -> ���� ū ����� ���� => �迭 ��� �� ������ ��.
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
                if (*(ptr + i * SIZE * SIZE + j * SIZE + k) > max) // �迭�� SIZE�� ����Ǽ� SIZE��ŭ �پ�Ѿ�� ��.(�����͸� ����)
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