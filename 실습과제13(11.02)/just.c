#include <stdio.h>
#include <string.h>

void storing(int n, char *ptr[]);
void counting(int k, int a, char *ptr[]);
void sorting(int n, int x[], char *b[]);
void printing(int n, int x[], char *b[]);

char *ptr[100];
char *fruit[100];
int cnt[100] = {0};
int c = 0;

int main()
{
    int n;
    scanf("%d", &n);
    char str[100][20];
    getchar();

    for (int i = 0; i < n; i++)
    {
        gets(str[i]);
    }

    for (int i = 0; i < n + 1; i++)
    {
        ptr[i] = str[i];
    }
    storing(n, ptr);
    counting(n, c, ptr);
    sorting(c, cnt, fruit);
    printing(c, cnt, fruit);

    return 0;
}

void storing(int n, char *ptr[])
{
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int found = 0;

        while (j < c)
        {
            if (strcmp(fruit[j], ptr[i]) == 0)
            {
                found = 1;
                break;
            }
            j++;
        }

        if (found == 0)
        {
            fruit[c] = ptr[i];
            c++;
        }
    }
}

void counting(int k, int a, char *ptr[])
{

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (strcmp(ptr[j], fruit[i]) == 0)
            {
                cnt[i]++;
            }
        }
    }
}

void sorting(int n, int x[], char *b[])
{
    char *temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            int compare = strcmp(b[j], b[j + 1]);

            if (x[j] < x[j + 1] || (x[j] == x[j + 1] && compare > 0))
            {
                int t = x[j];
                x[j] = x[j + 1];
                x[j + 1] = t;

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

void printing(int n, int x[], char *b[])
{

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d %s", x[i], b[i]);
        }
        else
        {
            printf("%d %s\n", x[i], b[i]);
        }
    }
}
