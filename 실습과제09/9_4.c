#include <stdio.h>

int fibo(int x);
unsigned long long total = 0;

int main()
{
    int x;
    scanf("%d", &x);
    fibo(x - 1);
    printf("%llu", total);
    return 0;
}

int fibo(int x)
{
    if (x == 0)
    {
        return total++;
    }
    else if (x == 1)
    {
        return total++;
    }
    else
    {
        return (fibo(x - 1) + fibo(x - 2));
    }
}