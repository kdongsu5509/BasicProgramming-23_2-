#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int arr[MAX_SIZE];

int compare(const void *a, const void *b);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(&arr[0], n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}

int compare(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}