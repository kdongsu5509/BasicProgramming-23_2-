#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int main()
{
    unsigned N, M;
    scanf("%u %u", &N, &M);
    int cnt = 0;

    if (N < 2)
    {
        N = 2; // Ensure N is at least 2, as 0 and 1 are not prime.
    }

    // Create a boolean array to mark primes using the Sieve of Eratosthenes.
    unsigned max = M;
    bool *is_prime = (bool *)malloc((max + 1) * sizeof(bool));
    if (is_prime == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array.
    for (unsigned i = 0; i <= max; i++)
    {
        is_prime[i] = true;
    }

    // Mark non-prime numbers.
    for (unsigned p = 2; p * p <= max; p++)
    {
        if (is_prime[p])
        {
            for (unsigned i = p * p; i <= max; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    // Count palindromic prime numbers in the range.
    for (unsigned i = N; i <= M; i++)
    {
        if (is_prime[i] && is_palindrome(i))
        {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    free(is_prime);
    return 0;
}
