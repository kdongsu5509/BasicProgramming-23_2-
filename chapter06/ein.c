#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    (a % 2) ? printf("%s", "odd") : printf("%s", "even");
    return 0;
}