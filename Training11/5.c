/// compile error.

#include <stdio.h>
#define MAX 10

void swap(int a[], int i, int j);
void bubblesort(int n, int a[]);

/* converts decimal digits into array a[] */
int scan(int n, int a[]);

/* returns 1 if all the elements of a[] and b[]
 * are equal in the range from 0 to n - 1.
 * returns 0, otherwise.
 */
int comp(int n, int a[], int b[]);

int main()
{
    int n, t, m, a[MAX], b[MAX], cnt = 0;
    scanf("%d", &n);
    int len = scan(n, a);
    // printf("the len is %d\n", len);
    bubblesort(len, a);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &m);
        int lenm = scan(m, b);
        bubblesort(lenm, b);
        if (len == lenm && comp(len, a, b))
            cnt++;
    }
    printf("%d %d", n, cnt);
}

int comp(int n, int a[], int b[])
{
    for (int x = 0; x < n; x++)
    {
        if (a[x] != b[x])
        {
            return 0;
        }
    }

    return 1;
}

int scan(int n, int a[])
{
    // 배열에 한 숫자씩 넣고 길이를 출력합니다
    int count = 0;
    // int a[] = num을 넣는 곳입니다.
    while (n != 0)
    {
        int temp = n % 10;
        a[count] = temp;
        n /= 10;
        count++;
    }
    return count;
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