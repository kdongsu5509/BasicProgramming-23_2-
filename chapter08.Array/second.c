#include <stdio.h>

int alphabet[26] = {0};

int main()
{
    int num = 0;
    char UserIn[1024];

    scanf("%d", &num);
    for (int l = 0; l < num + 1; l++)
    {
        UserIn[l] = getchar();
    }

    /*아스키 코드를 찾고 그 값에 따른 배열의 위치에 가중치를 줌*/
    for (int i = 0; i < num + 1; i++)
    {
        int ascA, asc, wa;
        ascA = (int)"A";
        asc = (int)UserIn[i];
        wa = asc - (int)"A";
        alphabet[wa]++;
        printf("%d", ascA);
    }

    int max = 0;
    /*가장 많이 쓰인 하나의 단어를 찾음.
    단 큰 경우에만 대체되므로 작은 값이 가장 먼저임*/
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
            printf("%d", z + 65);
        }
        else
        {
            printf("%s", "Nothing");
        }
    }
    /*배열 해서 a아스키 코드 값 빼서. -> 배열의 주소에 있는 값을 하나씩 증가 시키는 메타*/
    /*최근에 푼 백준 문제랑 비슷한 것 같은데..?*/
    /*최대값은 다른 변수로 관리해서 for loop를 돌리기. 단, 문자열 배열, 혹은 숫자 배열에 넣을까?*/
    /*여러개 찾아야 하니까....두 개 이상인 경우 특정 변수에 저장해놓자.<-그럼 포인터로 저장해놓을까?*/
    /*나타난 순서대로.... 아니 포인터 이 새끼 괜찮은듯.?*/
    return 0;
}