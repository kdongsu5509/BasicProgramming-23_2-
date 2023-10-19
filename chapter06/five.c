#include <stdio.h>

int main()
{
    int year, month;
    scanf("%d %d", &year, &month);

    int yoon = 0;
    if ((!(year % 4)))
    {
        yoon = yoon + 1;
    }
    if (!(year % 100))
    {
        yoon = yoon - 1;
    }
    if (!(year % 400))
    {
        yoon = yoon + 1;
    }

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("%d", 31);
        break;
    case 2:
        if (yoon == 0)
        {
            printf("%d", 28);
            break;
        }
        else if (yoon == 1)
        {
            printf("%d", 29);
            break;
        }
    default:
        printf("%d", 30);
    }

    return 0;
}