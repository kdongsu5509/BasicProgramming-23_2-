// #include <stdio.h>
// typedef unsigned long long ull;
// int main()
// {
//     ull num = 0;
//     int oneCount = 0, zeroCount = 0;
//     scanf("%llu", num);
//     int zeroOrOne = 1; // 1이면 1, 0이면 0
//     int MaxNum = 0;
//     while (num > 0)
//     {
//         if (num & 1)
//         {
//             zeroOrOne = 1;
//         }
//         while (zeroOrOne)
//         {
//             if (num & 1)
//             {
//                 oneCount++;
//                 num = num >> 1;
//             }
//             else
//             {
//                 MaxNum = oneCount;
//                 oneCount = 0;
//                 zeroOrOne = 0;
//                 num = num >> 1;
//             }
//         }
//     }
//     printf("%d", MaxNum);

//     return 0;
// }

#include <stdio.h>

typedef unsigned long long ull;

int main()
{
    ull num = 0;
    int oneCount = 0, maxOneCount = 0;

    scanf("%llu", &num);

    while (num > 0)
    {
        if (num & 1)
        {
            oneCount++;
        }
        else
        {
            if (oneCount > maxOneCount)
            {
                maxOneCount = oneCount;
            }
            oneCount = 0;
        }
        num >>= 1;
    }

    if (oneCount > maxOneCount)
    {
        maxOneCount = oneCount;
    }

    printf("%d", maxOneCount);

    return 0;
}