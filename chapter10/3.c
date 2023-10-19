#include <stdio.h>
#include <math.h>

unsigned factor_cnt = 0;
unsigned factors[100];

void factorize(unsigned n);

int main()
{
    unsigned N;
    scanf("%u", &N);
    factorize(N);
    for (int i = 0; i < factor_cnt; i++)
        printf("%u ", factors[i]);
}

// // void factorize(unsigned n)
// // {
// //     unsigned sub = n;

// //     if (n == 2)
// //     {
// //         factor_cnt == 1;
// //         factors[0] = 2;
// //         return;
// //     }

// //     for (int i = 2; i <= sqrt(n); i++)
// //     {
// //         if (sub % i == 0)
// //         {
// //             factors[factor_cnt] = i;
// //             factor_cnt++;
// //             while ((sub % i) == 0)
// //             {
// //                 factor_cnt++;
// //                 printf("factor cnt is %u\n", factor_cnt);
// //                 sub /= i;
// //             }
// //         }
// //     }
// // }

// // void factorize(unsigned n)
// // {
// //     unsigned sub = n;

// //     if (n == 2)
// //     {
// //         factor_cnt = 1;
// //         factors[0] = 2;
// //         return;
// //     }

// //     for (int i = 2; i <= sqrt(n); i++)
// //     {
// //         if (sub % i == 0)
// //         {
// //             factors[factor_cnt] = i;
// //             factor_cnt++;
// //             while ((sub % i) == 0)
// //             {
// //                 sub /= i;
// //             }
// //         }
// //     }
// //     ++factor_cnt;
// //     factors[factor_cnt] = sub;
// // }

// void factorize(unsigned n)
// {
//     // unsigned sub = n;

//     // if (n == 2)
//     // {
//     //     factor_cnt = 1;
//     //     factors[0] = 2;
//     //     return;
//     // }

//     for (unsigned i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             while ((n % i) == 0)
//             {
//                 n /= i;
//             }
//             factors[factor_cnt] = i;
//             factor_cnt++;
//         }
//     }

//     if (n > 1)
//     {
//         factors[factor_cnt] = n;
//         ++factor_cnt;
//     }
// }

// // 아니 시발 뭐가 문제야

void factorize(unsigned n)
{
    factor_cnt = 0;

    // 2로 나눌 수 있는 만큼 나누고 나머지를 n에 저장합니다.
    while (n % 2 == 0)
    {
        factors[factor_cnt++] = 2;
        n /= 2;
    }

    // 3 이상의 홀수 소수로 나눠서 소인수를 찾습니다.
    for (unsigned i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            factors[factor_cnt++] = i;
            n /= i;
        }
    }

    // n이 아직 1이 아니면, 마지막 소인수를 factors 배열에 추가합니다.
    if (n > 1)
    {
        factors[factor_cnt++] = n;
    }
}