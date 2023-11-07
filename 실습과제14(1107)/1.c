#include <stdio.h>

void reverse(char *str);

int main()
{
    char str[100];
    gets(str);
    reverse(str);
    puts(str);
}

void reverse(char *str)
{
    char *t = str;
    char rep[100];
    while (*t != 0)
    {
        t++;
    }
    t--;
    char *temp = t;
    int i = 0;
    while (t >= str)
    {
        rep[i] = *t;
        // printf("adress down progress. %c\n", *t);
        t--;
        i++;
    }
    // printf("%s\n", rep);
    int ni = 0;
    while (temp >= str)
    {
        *(str + ni) = *(rep + ni);
        temp--;
        ni++;
    }
}