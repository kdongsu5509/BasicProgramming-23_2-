#include <stdio.h>

int main()
{
    int num, p = 0;
    scanf("%d", &num);
    if (num < 3)
    {
        printf(0);
    }
    for (int a = 1; a < num; a++)
    {
        for (int b = 1; b < num; b++)
        {
            for (int c = 1; c < num; c++)
            {
                if ((a + b + c) == num)
                {
                    if ((a <= b) && (b <= c))
                    {
                        p = p + 1;
                    }
                }
            }
        }
    }
    printf("%d", p);
    return 0;
}