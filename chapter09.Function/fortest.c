#include <stdio.h>
#include <math.h>

typedef unsigned long long ulong_t;
typedef unsigned int uint_t;

uint_t countDivisors(ulong_t n);

int main() {
    uint_t N, M;
    scanf("%u %u", &N, &M);

    ulong_t maxDivisors = 0;
    ulong_t maxNumber = 0;

    for (ulong_t number = N; number <= M; number++) {
        uint_t divisors = countDivisors(number);
        if (divisors >= maxDivisors) {
            maxDivisors = divisors;
            maxNumber = number;
        }
    }

    printf("%llu\n", maxNumber);
    printf("%llu", maxDivisors);

    return 0;
}

uint_t countDivisors(ulong_t n) {
    uint_t count = 0;

    for (ulong_t i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2; // 두 개의 약수(i와 n/i)를 더합니다.
            }
        }
    }

    return count;
}
