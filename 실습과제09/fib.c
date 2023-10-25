#include <stdio.h>

typedef long long int;

int fibo(int x);

int main()
{
    int x = fibo(8);
    printf("%d", x);
    return 0;
}

int fibo(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else if (x == 1)
    {
        return 1;
    }
    else
    {
        return (fibo(x - 1) + fibo(x - 2));
    }
}
