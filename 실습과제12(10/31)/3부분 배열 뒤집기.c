#include <stdio.h>

void reverse(int from, int to, int *ptr);

int main()
{
    int n, from, to, arr[100];
    scanf("%d %d %d", &n, &from, &to);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    reverse(from, to, arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void reverse(int from, int to, int *ptr)
{
    for (int i = 0; i < ((to - from + 1) / 2); i++)
    {
        int t = *(ptr + from + i);
        *(ptr + from + i) = *(ptr + (to - i));
        *(ptr + (to - i)) = t;
    }
}