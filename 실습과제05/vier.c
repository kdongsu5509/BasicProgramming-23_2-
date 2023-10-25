#include <stdio.h>
#include <string.h>

int main()
{
    char op[5];
    scanf("%s", op);
    char xp[5] = "/";
    char yp[5] = "+";
    char zp[5] = "-";
    char kp[5] = "*";
    int a = 0, b = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    if (!strcmp(op, xp))
    {
        printf("%d = %d * %d + %d", a, b, a / b, a % b);
    }
    else if (!strcmp(op, yp))
    {
        printf("%d %s %d = %d", a, op, b, a + b);
    }
    else if (!strcmp(op, zp))
    {
        printf("%d %s %d = %d", a, op, b, a - b);
    }
    else if (!strcmp(op, kp))
    {
        printf("%d %s %d = %d", a, op, b, a * b);
    }
    return 0;
}