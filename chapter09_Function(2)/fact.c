/*나중 문제 풀 때 개꿀빨라고 만들어놓은 함수 1*/

#include <stdio.h>

int factorial(int x);

int main()
{
    int p = factorial(5);
    printf("%d", p);
    return 0;
}

int factorial(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return x * (factorial(x - 1));
    }
}