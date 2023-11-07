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

//집 3개가 있다. 그 집 3개에 입주자들만 바꾸는 것이 가능하다!!(포인터를 사용한다면)