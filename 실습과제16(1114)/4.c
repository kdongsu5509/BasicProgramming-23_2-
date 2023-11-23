#include <stdio.h>

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

void *which_function(char op);

int main()
{
    int n;
    double a, b;
    char op;
    double (*f)(double x, double y);

    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf %c %lf", &a, &op, &b);
        f = which_function(op);
        printf("%.4lf\n", f(a, b));
    }
}

void *which_function(char op)
{
    if (((int)(op)) == 43)
    {
        return add;
    }
    else if (((int)(op)) == 45)
    {
        return sub;
    }
    else if (((int)(op)) == 42)
    {
        return mul;
    }
    else if (((int)(op)) == 47)
    {
        return div;
    }
}

double add(double x, double y)
{
    double re = 0;
    re = x + y;
    return re;
}
double sub(double x, double y)
{
    double re = 0;
    re = x - y;
    return re;
}
double mul(double x, double y)
{
    double re = 0;
    re = x * y;
    return re;
}
double div(double x, double y)
{
    double re = 0;
    re = x / y;
    return re;
}
