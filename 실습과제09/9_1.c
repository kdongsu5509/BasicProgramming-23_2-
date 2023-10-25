#include <stdio.h>

int gcd(int n, int m);
int lcm(int n, int m);

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d\n", gcd(N, M));
    printf("%d\n", lcm(N, M));
}

int gcd(int n, int m)
{
    int org_n = n;
    int org_m = m;
    if (m == 0)
    {
        return n;
    }
    else
    {
        return gcd(org_m, org_n % org_m);
    }
}

int lcm(int n, int m)
{
    int multi = gcd(n, m);
    int new_a = (n / multi) * m;
    return new_a;
}