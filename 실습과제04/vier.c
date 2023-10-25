#include <stdio.h>

int main()
{
    long long allNumber = 0x3FFFFFF;

    char a = getchar();
    getchar();
    char b = getchar();
    getchar();
    char c = getchar();

    int aNum = (int)a - 'A';
    int bNum = (int)b - 'A';
    int cNum = (int)c - 'A';

    int aFinal = (1 << aNum);
    int bFinal = (1 << bNum);
    int cFinal = (1 << cNum);

    int printValue = (allNumber & (~aFinal));
    printValue = printValue & (~bFinal);
    printValue = printValue & (~cFinal);

    // int printVariable = ~(aFinal + bFinal + cFinal);
    printf("%07x", printValue);
    return 0;
}

/*비트 이동한 놈이랑 전체값이랑 & --> 굳굳*/