#include <stdio.h>

int main()
{
    long long UserIn;
    scanf("%lld", &UserIn);
    long long first[10] = {0};
    long long second[10] = {0};
    /*첫 번쨰 배열에 입력하는 값 입니다.*/
    for (int i = 0; i < UserIn; i++)
    {
        long long num;
        scanf("%lld", &num);
        first[i] = num;
    }
    /*두 번째 배열에 입력하는 값 입니다.*/
    for (int j = 0; j < UserIn; j++)
    {
        long long num;
        scanf("%lld", &num);
        second[j] = num;
    }
    /*계산하여 출력하는 부분입니다*/
    for (int x = 0; x < UserIn; x++)
    {
        long long print;
        print = first[x] + second[x];
        if (x == UserIn - 1)
        {
            printf("%lld ", print);
        }
        else
        {
            printf("%lld ", print);
        }
    }

    return 0;
}