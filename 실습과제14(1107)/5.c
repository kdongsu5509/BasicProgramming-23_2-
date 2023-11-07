// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int Num[100] = {0};
// char Words[100];

// void bubblesort(int n, char *ptr[]);
// void a_bubblesort(int n, char A[], int Num[])
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (Num[j] > Num[j + 1])
//             {
//                 int temp = Num[j];
//                 char t[20];
//                 strcpy(temp, A[j]);
//                 Num[j + 1] = Num[j];
//                 strcpy(A[j + 1], A[j]);
//                 Num[j] = temp;
//                 strcpy(A[j], temp);
//             }
//         }
//     }
// }
// int counting(int n, char *ptr[])
// {

//     char temp[20] = **ptr;
//     int cnt = 0;
//     int fNum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if ((strcmp(temp, ptr[i])) == 0)
//         {
//             cnt++;
//         }
//         else
//         {
//             Num[fNum] = cnt;
//             Words[fNum] = temp;
//             strcpy(temp, ptr[i]);
//             cnt = 0;
//             fNum++;
//             continue;
//         }
//     }
// }

// int main()
// {
//     int N;
//     scanf("%d", &N);

//     char Array[100][20];
//     for (int i = 0; i < N; i++)
//     {
//         gets(Array[i]);
//     }

//     char *ptr[10];
//     for (int i = 0; i < N; i++)
//         ptr[i] = Array[i];
//     bubblesort(N, ptr);
//     counting(N, ptr);
//     int s = strlen(Words);
//     a_bubblesort(s, Words, Num);

//     // 정렬함수 -> 알파벳 순서대로 한다.
//     // 개수를 카운팅 한다
//     // 새로운 배열에 정렬한다.  -> 최대값 찾고, 그 다음 최대값 찾고 --->>>>>>>(같이 바꾸면 된다.)
//     // 출력한다.

//     return 0;
// }

// void bubblesort(int n, char *ptr[])
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (strlen(ptr[j]) == strlen(ptr[j + 1]))
//             {
//                 if (strcmp(ptr[j], ptr[j + 1]) > 0)
//                 {
//                     char temp[20];
//                     strcpy(temp, (ptr[j]));
//                     strcpy((ptr[j]), (ptr[j + 1]));
//                     strcpy((ptr[j + 1]), temp);
//                 }
//             }
//             else if (strlen(ptr[j]) > strlen(ptr[j + 1]))
//             {

//                 char temp[20];
//                 strcpy(temp, (ptr[j]));
//                 strcpy((ptr[j]), (ptr[j + 1]));
//                 strcpy((ptr[j + 1]), temp);
//             }
//         }
//     }
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Num[100] = {0};
char Words[100][20];

void bubblesort(int n, char *ptr[]);
void a_bubblesort(int n, char A[][20], int Num[]);
int counting(int n, char *ptr[]);

int main()
{
    int N;
    scanf("%d", &N);
    getchar(); // 입력 버퍼에 남아 있는 개행 문자를 소비합니다.

    char Array[100][20];
    for (int i = 0; i < N; i++)
    {
        gets(Array[i]);
    }

    char *ptr[100];
    for (int i = 0; i < N; i++)
        ptr[i] = Array[i];
    bubblesort(N, ptr);
    int s = counting(N, ptr);
    a_bubblesort(s, Words, Num);

    for (int i = 0; i < s; i++)
    {
        printf("%d %s\n", Num[i], Words[i]);
    }

    return 0;
}

void bubblesort(int n, char *ptr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strlen(ptr[j]) == strlen(ptr[j + 1]))
            {
                if (strcmp(ptr[j], ptr[j + 1]) > 0)
                {
                    char temp[20];
                    strcpy(temp, ptr[j]);
                    strcpy(ptr[j], ptr[j + 1]);
                    strcpy(ptr[j + 1], temp);
                }
            }
            else if (strlen(ptr[j]) > strlen(ptr[j + 1]))
            {
                char temp[20];
                strcpy(temp, ptr[j]);
                strcpy(ptr[j], ptr[j + 1]);
                strcpy(ptr[j + 1], temp);
            }
        }
    }
}

int counting(int n, char *ptr[])
{
    int cnt = 1;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && strcmp(ptr[i], ptr[i + 1]) == 0) // strcmp()에서 오류 발생 방지위해 n-1까지
        {
            cnt++;
        }
        else
        {
            strcpy(Words[s], ptr[i]);
            Num[s] = cnt;
            cnt = 1;
            s++;
        }
    }

    return s;
}

void a_bubblesort(int n, char A[][20], int Num[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Num[j] < Num[j + 1] || (Num[j] == Num[j + 1] && strcmp(A[j], A[j + 1]) > 0))
            {
                int temp = Num[j];
                Num[j] = Num[j + 1];
                Num[j + 1] = temp;
                char tempWord[20];
                strcpy(tempWord, A[j]);
                strcpy(A[j], A[j + 1]);
                strcpy(A[j + 1], tempWord);
            }
        }
    }
}
