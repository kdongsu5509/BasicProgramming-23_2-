#include <stdio.h>

// 함수 원형 선언
int findLCM(int a, int b);
int findMultipleLCM(int arr[], int n, int index);

int main()
{
    int n;

    // 사용자로부터 숫자의 개수 입력
    printf("숫자의 개수를 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("유효한 숫자의 개수를 입력하세요.\n");
        return 1;
    }

    int numbers[n];

    // 숫자 입력
    for (int i = 0; i < n; i++)
    {
        printf("숫자 %d 입력: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // 입력한 숫자들의 최소 공배수 계산
    int result = findMultipleLCM(numbers, n, 0);

    printf("입력한 숫자들의 최소 공배수: %d\n", result);

    return 0;
}

// 최대 공약수 계산 함수 (유클리드 호제법 사용)
int findGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return findGCD(b, a % b);
}

// 최소 공배수 계산 함수
int findLCM(int a, int b)
{
    return (a * b) / findGCD(a, b);
}

// 여러 숫자의 최소 공배수 계산 함수 (재귀적으로 호출)
int findMultipleLCM(int arr[], int n, int index)
{
    if (index == n - 1)
    {
        return arr[index];
    }

    int lcm = findLCM(arr[index], findMultipleLCM(arr, n, index + 1));

    return lcm;
}
