#include <stdio.h>

int *find_largest(int n, int *ptr);

int main()
{
    int n, arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int *p = find_largest(n, arr);
    printf("%d", *p);
}

int *find_largest(int n, int *ptr)
{
    int *init = ptr; // 주소 저장
    for (int i = 1; i < n; i++)
    {
        if (*init < *(ptr + i)) // 역참조하여 값을 비교
        {
            init = ptr + i; // 클 경우 주소를 바꿈.
        }
    }
    return init;
}