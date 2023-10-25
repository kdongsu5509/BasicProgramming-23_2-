#include <stdio.h>

int main()
{
    int a, b, c, max, min, cntEven, cntOdd;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    max = a;
    max = (max < b) ? b : max;
    max = (max < c) ? c : max;

    min = a;
    min = (min > b) ? b : min;
    min = (min > c) ? c : min;

    cntEven = 0;
    cntOdd = 0;
    (a % 2) ? ++cntOdd : ++cntEven;
    (b % 2) ? ++cntOdd : ++cntEven;
    (c % 2) ? ++cntOdd : ++cntEven;

    printf("%d %d\n", max, min);
    printf("%d %d\n", cntOdd, cntEven);

    return 0;
}