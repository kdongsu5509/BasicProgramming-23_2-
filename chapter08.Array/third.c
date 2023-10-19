#include <stdio.h>

/*메모리 동적 할당 안함
대신에 큰 값을 주고 출력 부분만 제한*/
int First[10][10];
int Second[10][10];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    /*입력과 동시에 다시 넣음*/
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < M; b++)
        {
            int i;
            scanf("%d", &i);
            Second[b][a] = i;
        }
    }

    for (int b = 0; b < M; b++)
    {
        for (int a = 0; a < N; a++)
        {
            if (a == N - 1)
            {
                printf("%d\n", Second[b][a]);
            }
            else
            {
                printf("%d ", Second[b][a]);
            }
        }
    }
    return 0;
}