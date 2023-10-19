#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    double root = sqrt((b * b) + (-1 * (4 * a * c)));
    double finalFirst = ((-1 * b) + root) / (double)(2 * a);
    double finalSecond = ((-1 * b) + (-1 * root)) / (double)(2 * a);

    printf("%.4f\n", finalFirst);
    printf("%.4f\n", finalSecond);
    return 0;
}