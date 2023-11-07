#include <stdio.h>
#define SIZE 100

int is_palindrome(char *s, char *t);

int main()
{
    int n;
    char str[SIZE];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        scanf("%c", &str[i]);
    printf(is_palindrome(str, str + n - 1) ? "yes" : "no");
}

int is_palindrome(char *s, char *t)
{
    int size = t - s;
    for (int i = 0; i < size; i++)
    {
        if (*(s + i) != *(t - i))
        {
            return 0;
        }
    }
    return 1;
}