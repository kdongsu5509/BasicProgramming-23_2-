#include <stdio.h>

int main()
{
    int Num = 0;
    scanf("%d", &Num);
    if ((Num % 3) == 0 && (Num % 5) != 0)
    {
        printf("%s", "pizza");
    }
    else if ((Num % 3) != 0 && (Num % 5) == 0)
    {
        printf("%s", "chicken");
    }
    else if ((Num % 3) == 0 && (Num % 5) == 0)
    {
        printf("%s", "combo");
    }
    else
    {
        printf("%s", "diet");
    }
    return 0;
}