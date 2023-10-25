uint_t divcnt(uint_t n) // 카운트 놈으로
{
    uint_t cnt = 0;
    if (n == 1)
    {
        cnt = 1;
        return cnt;
    }
    for (ulong_t i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            cnt += 1;
        }
        else
        {
            if (n % i == 0)
            {
                cnt += 2;
            }
        }
    }
    return cnt;
}

void solve(uint_t N, uint_t M)
{
    unsigned long long max_cnt = 0;
    unsigned long long max = 0;

    for (unsigned long long x = N; x <= M; x++)
    {
        uint_t cnt = divcnt(x);
        if (max_cnt <= cnt)
        {
            max_cnt = cnt;
            max = x;
        }
    }

    printf("%llu\n", max);
    printf("%llu\n", max_cnt);
}