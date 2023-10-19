#include <stdio.h>

int main()
{

    char a = getchar();

    int cnt = 0;

    cnt += (a & 1) ? 1 : 0;
    cnt += ((a >> 1) & 1) ? 1 : 0;
    cnt += ((a >> 2) & 1) ? 1 : 0;
    cnt += ((a >> 3) & 1) ? 1 : 0;
    cnt += ((a >> 4) & 1) ? 1 : 0;
    cnt += ((a >> 5) & 1) ? 1 : 0;
    cnt += ((a >> 6) & 1) ? 1 : 0;
    cnt += ((a >> 7) & 1) ? 1 : 0;

    printf("%d\n", a);
    printf("0x%x\n", a);
    printf("%d", cnt);
    return 0;
}