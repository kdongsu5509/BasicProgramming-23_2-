#include <stdio.h>

int alphabet[26] = {0};

int main()
{
    int num = 0;
    char UserIn[1024];

    scanf("%d\n", &num);
    for (int l = 0; l < num; l++)
    {
        UserIn[l] = getchar();
    }
    UserIn[num] = '\0'; // 문자열 끝을 나타내는 NULL 문자 추가

    /* 아스키 코드를 찾고 그 값에 따른 배열의 위치에 가중치를 줌 */
    for (int i = 0; i < num; i++)
    {
        int ascA, asc, wa;
        ascA = (int)'A';
        asc = (int)UserIn[i];
        wa = asc - ascA;
        alphabet[wa]++;
    }

    int max = 0;
    /* 가장 많이 쓰인 하나의 단어를 찾음 */
    for (int x = 0; x < 26; x++)
    {
        if (max < alphabet[x])
        {
            max = alphabet[x];
        }
    }

    for (int z = 0; z < 26; z++)
    {
        if (alphabet[z] == max)
        {
            printf("%d\n", z + 'A');
        }
    }

    return 0;
}