#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
}

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

//�� 3���� �ִ�. �� �� 3���� �����ڵ鸸 �ٲٴ� ���� �����ϴ�!!(�����͸� ����Ѵٸ�)