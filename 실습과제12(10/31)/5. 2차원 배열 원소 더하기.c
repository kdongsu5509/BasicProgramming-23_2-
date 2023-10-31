#include <stdio.h>

int add(int n, int m, int a, int b, int c, int d, int *ptr);

int main()
{
    int n, m, a, b, c, d, arr[100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n * m; i++)
        scanf("%d", &arr[i]);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d", add(n, m, a, b, c, d, arr));
}

int add(int n, int m, int a, int b, int c, int d, int *ptr) // 한 놈만 출력하면 되노
{
    // A[a][b] + A[c][d]출력
    int prt = 0;
    int eins = *(ptr + m * a + b); // 역참조 할 것임.
    int zwei = *(ptr + m * c + d);

    prt = eins + zwei;

    return prt;
}