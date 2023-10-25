#include <stdio.h>

int main()
{
    int a, b, c;

    a = (int)getchar() - (int)('0');
    b = (int)getchar() - (int)('0');
    c = (int)getchar() - (int)('0');

    int sum = a + b + c;
    printf("%d", sum);
    return 0;
}