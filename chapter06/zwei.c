#include <stdio.h>

int main()
{
    int fiveNum[5] = {0};

    scanf("%d", &fiveNum[0]);
    scanf("%d", &fiveNum[1]);
    scanf("%d", &fiveNum[2]);
    scanf("%d", &fiveNum[3]);
    scanf("%d", &fiveNum[4]);

    for (int i = 0; i < 5; i++)
    {
        int np = fiveNum[i];
        int cnt = 0;
        for (int x = 0; x < 5; x++)
        {
            if (np > fiveNum[x])
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            printf("%d\n", np);
        }
        //cnt = 0;
    }
    return 0;
}