#include <stdio.h>

// 모듈러 연산이 잘 안됩니다...ㅎㅎ
// 그래서 그냥 함수 만들어서 쓸게요!

int caesar(int x, int n);

int main()
{
    int a = getchar();
    int b = getchar();
    int c = getchar();
    int n;
    scanf("%d", &n);

    int na, nb, nc;
    na = caesar(a, n);
    nb = caesar(b, n);
    nc = caesar(c, n);

    putchar(na);
    putchar(nb);
    putchar(nc);
    return 0;
}

int caesar(int x, int n)
{
    int nn = n % 26;

    int plus = x + nn;
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