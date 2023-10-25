#include <stdio.h>

int main()
{
    int a = getchar();
    printf("%c\n", a);
    printf("%d\n", a);
    printf("8진수 원래는 0%o\n", a);
    printf("16진수 원래는 0x%x\n", a);
    printf("%o\n", a);
    printf("%x\n", a);
    return 0;
}