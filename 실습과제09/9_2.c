#include <stdio.h>

typedef unsigned long long ull_t;

ull_t gcd(ull_t n, ull_t m);
ull_t lcm(ull_t n, ull_t m);
ull_t solve(int n);

int main()
{
    int N;
    scanf("%d", &N);
    printf("%llu", solve(N));
}

ull_t gcd(ull_t n, ull_t m)
{
    ull_t org_n = n;
    ull_t org_m = m;
    if (m == 0)
    {
        return n;
    }
    else
    {
        return gcd(org_m, org_n % org_m);
    }
}

ull_t lcm(ull_t n, ull_t m)
{
    ull_t multi = gcd(n, m);
    ull_t new_a = (n / multi) * m;
    return new_a;
}

// ull_t solve(int n)
// {
//     ull_t arr[n];
//     ull_t save = 1;
//     for (ull_t i = 0; i < n; i++)
//     {
//         scanf("%llu", &arr[i]);
//     }
//     for (ull_t x = 0; x < n - 1; x++)
//     {
//         ull_t temp = lcm(save, arr[x + 1]);
//         save = temp;
//     }
//     return save;
// }

ull_t solve(int n)
{
    ull_t comp1 = 1;
    ull_t comp2 = 0;
    ull_t temp;

    scanf("%llu", &comp2);
    comp1 = lcm(comp1, comp2);

    if (n == 0)
    {
        return comp1;
    }
    else
    {
        return lcm(comp1, solve(n - 1));
    }
}