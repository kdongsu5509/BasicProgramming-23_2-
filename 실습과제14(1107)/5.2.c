// 전역 선언 사용 않고, main에서 컨트롤을 어떻게 할까는 의문점에서 시작
// 포인터를 적절히 활용하면 가능할 듯 하지만, 생각으로만 풀기에는 한계 존재
// 그래서 그냥 적으면서 시작.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubblesort(int n, char *ptr[]);
void a_bubblesort(int n, char *A, int *Num);
int counting(int n, char *ptr[], char *A, int *Num);

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
    int Num[100] = {0};
    char Words[100][20];
    int s = counting(N, ptr, Words, Num);
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

int counting(int n, char *ptr[], char *A, int *Num)
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
            strcpy((A + s), ptr[i]);
            *(Num + s) = cnt;
            cnt = 1;
            s++;
        }
    }

    return s;
}

void a_bubblesort(int n, char *A, int *Num)
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
