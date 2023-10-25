#include <stdio.h>

// 모듈러 연산이 잘 안됩니다...ㅎㅎ
// 그래서 그냥 함수 만들어서 쓸게요!

int caesar(int x);

int main()
{
    int a = getchar();
    int b = getchar();
    int c = getchar();

        int na, nb, nc;
    na = caesar(a);
    nb = caesar(b);
    nc = caesar(c);

    putchar(na);
    putchar(nb);
    putchar(nc);
    return 0;
}

int caesar(int x)
{
    int plus = x + 13;
    if (plus < 91)
    {
        return plus;
    }
    else
    {
        int newPlus = plus - 26;
        return newPlus;
    }
}