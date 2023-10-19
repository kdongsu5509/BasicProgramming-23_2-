#include <stdio.h>
#define MAX 1000

int cnt;

/* swaps the elements of a[i] and a[j] */
void swap(int a[], int i, int j);
/* sorts the elements of a[] indexed from 0 to n-1.*/
void bubblesort(int n, int a[]);

int main()
{
    int N, A[MAX];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    cnt = 0;
    bubblesort(N, A);
    printf("%d\n", cnt);
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
}

void bubblesort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++) // n값이 배열 사이즈 기준으로 주어지는지 아니면 일반적 상식 기준에서 크기로 주어지는 지 따라서 코드 수정할 것.
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // printf("a[j], a[j + 1] is %d %d\n", a[j], a[j + 1]);
                swap(a, j, j + 1);
                cnt++;
            }
        }
    }
}

void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}