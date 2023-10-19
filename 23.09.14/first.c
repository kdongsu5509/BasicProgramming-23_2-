#include <stdio.h>

int main()
{
    int a = getchar();
    printf("%c\n", a);
    printf("%d\n", a);
    printf("0%o\n", a);
    printf("0x%x\n", a);
    return 0;
}