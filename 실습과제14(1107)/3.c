#include <stdio.h>
#include <string.h>

void bubblesort(int n, char *ptr[]);

int main()
{
    int n;
    scanf("%d\n", &n);
    char str[10][20];
    for (int i = 0; i < n; i++)
        gets(str[i]);
    char *ptr[10];
    for (int i = 0; i < n; i++)
        ptr[i] = str[i];
    bubblesort(n, ptr);
    for (int i = 0; i < n; i++)
        puts(ptr[i]);
}

void bubblesort(int n, char *ptr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp((ptr[j]), (ptr[j + 1])) < 0)
            {
                char temp[20];
                strcpy(temp, (ptr[j]));
                strcpy((ptr[j]), (ptr[j + 1]));
                strcpy((ptr[j + 1]), temp);
            }
        }
    }
}
