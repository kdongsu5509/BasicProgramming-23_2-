/*이진수 팰린드롬*/

isPalindrome(unsigned int n);

isPalindrome(unsigned int n)
{
    /*비트 마스크 연산해야징
    i랑 k-i번째 비트 비교해야징*/
    if (n != 0)
    {
        return 0;
    }
}

int is_palindrome(unsigned n)
{
    int numBits = sizeof(n) * 8;
    int left = 0;
    int right = numBits - 1;

    while (left < right)
    {
        if (((n & (1 << left)) >> left) != ((n & (1 << right)) >> right))
        {
            return 0; // 이진수 팰린드롬이 아님
        }
        left++;
        right--;
    }

    return 1; // 이진수 팰린드롬임
}
/*이진수 팰린드롬*/

#include <stdio.h>

/* returns 1 if n is binary palindrome or 0 otherwise. */
int is_palindrome(unsigned n);

int main()
{
    unsigned T;
    scanf("%u", &T);
    while (T--)
    {
        unsigned n;
        scanf("%u", &n);
        is_palindrome(n) ? printf("yes\n") : printf("no\n");
    }
}

int is_palindrome(unsigned n)
{
    int left = 0;
    int right = sizeof(unsigned) * 8 - 1; // Calculate the number of bits in an unsigned int

    while (left < right)
    {
        if (((n >> left) & 1) != ((n >> right) & 1))
            return 0;

        left++;
        right--;
    }

    return 1;
}

// int is_palindrome(unsigned int n)
// {
//     unsigned long long temp = n;
//     size_t length = 0;

//     while (temp != 0)
//     {
//         length++;
//         temp = temp >> 1;
//     }
//     // printf("%zu", length);

//     printf("length is %zu\n", length);

//     for (int i = 0; i < length / 2; i++)
//     {
//         if ((n >> i) != (n >> (length - i - 1)))
//             return 0;
//     }

//     return 1;
// }

// int is_palindrome(unsigned n)
// {
//     unsigned reversed = 0;
//     unsigned original = n;

//     while (n > 0)
//     {
//         reversed = (reversed << 1) | (n & 1);
//         n = n >> 1;
//     }

//     return original == reversed ? 1 : 0;
// }
