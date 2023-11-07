#include <stdio.h>
#include <string.h>

void bubblesort(int n, char (*str)[20]);

int main()
{
    int n;
    scanf("%d\n", &n);
    char str[10][20];
    for (int i = 0; i < n; i++)
        gets(str[i]);
    bubblesort(n, str);
    for (int i = 0; i < n; i++)
        puts(str[i]);
}

// void bubblesort(int n, char (*str)[20])
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (strcmp((str + j), (str + j + 1)) < 0)
//             {
//                 char temp[20] = *(str + j);
//                 char A[20];
//                 char B[20];
//                 strcpy(A, str + j);
//                 strcpy(B, str + j + 1);
//                 (str + j) = A;
//                 (str + j + 1) = B;
//             }
//         }
//     }
// }

// strcpy는 덮어쓰긴인가???
void bubblesort(int n, char (*str)[20])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                char temp[20];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }
}
