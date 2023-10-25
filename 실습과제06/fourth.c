// #include <stdio.h>

// int main()
// {
//     int num = 0, time = 1;
//     scanf("%d", &num);
//     for (int i = 0; i < num; i++)
//     {
//         for (int j = 1; j <= i + 1; j++)
//         {
//             if (j + 1 == i)
//             {
//                 printf("%d", 2 * time - 1);
//                 time = time + 1;
//             }
//             else
//             {
//                 printf("%d", 2 * time - 1);
//                 printf(" ");
//                 time = time + 1;
//             }
//         }
//         if (!(i == num - 1))
//         {
//             printf("\n");
//         }
//     }
//     return 0;
// }

// 출력은 정상으로 되는데...

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int currentOdd = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", currentOdd);
            currentOdd += 2;
            if (j < i)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}