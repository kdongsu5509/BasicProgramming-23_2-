#include <stdio.h>

int main()
{
    int a, b;
    scanf("%o", &a);
    scanf("%x", &b);

    printf("%c %c\n", a, b);
    printf("%5d %5d %5d\n", (int)a, (int)b, (int)a + b);
    printf("%05o %05o %05o\n", a, b, a + b);
    printf("0x%03x 0x%03x 0x%03x\n", a, b, a + b);
    return 0;
}