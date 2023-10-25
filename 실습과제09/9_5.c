#include <stdio.h>

int ack(int n, int m, int n_deep);

int cnt = 0;
int deep = 0;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int result = ack(n, m, 1);

    printf("%d\n", result);
    printf("%d\n", cnt);
    printf("%d\n", deep);

    return 0;
}

int ack(int n, int m, int n_deep)
{
    cnt++;

    if (n_deep > deep)
    {
        deep = n_deep;
    }

    if (n == 0)
    {
        return m + 1;
    }
    else if (n > 0 && m == 0)
    {
        return ack(n - 1, 1, n_deep + 1);
    }
    else
    {
        int temp1 = ack(n, m - 1, n_deep + 1);
        return ack(n - 1, temp1, n_deep + 1);
    }
}