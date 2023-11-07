// 행렬의 최대원소 with prt

#include <stdio.h>
#define SIZE 100

int *mmax(int n, int m, int *x, int *a, int *b);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int A[SIZE][SIZE];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    int i, j;
    int *maxptr = mmax(n, m, &A[0][0], &i, &j);
    printf("%d %d %d %d", *maxptr, A[i][j], i, j);
}

int *mmax(int n, int m, int *x, int *a, int *b)
{
    // n과m은 각각 행과 열의 사이즈
    // x는 2차원 배열의 주소
    // a는 i의 주소
    // b는 j의 주소 =>
    int max = *(x);  // 배열의 첫 번째 요소 값을 최댓값으로 초기화
    int *maxptr = x; // maxptr를 배열의 첫 번째 요소를 가리키도록 초기화
    for (int q = 0; q < n; q++)
    {
        for (int z = 0; z < m; z++)
        {
            if (max < *(x + (q * SIZE) + z))
            {
                max = *(x + q * SIZE + z);
                maxptr = (x + (q * SIZE) + z);
                *a = (q * SIZE + z) - SIZE;
                *b = z;
            }
        }
    }
    return maxptr;
}

// 주요 변경 사항:

// max 및 maxptr를 올바르게 초기화합니다. max는 배열의 첫 번째 요소 값으로 초기화되고 maxptr는 배열의 첫 번째 요소를 가리키도록 초기화됩니다.
// 두 번째 for 루프의 순서를 변경하여 행(q) 먼저 반복하고 그 다음에 열(z)을 반복합니다.
// *(x + q * m + z)를 사용하여 배열 요소에 접근합니다. (q * m + z)는 2D 배열을 1차원 배열로 표현하는 방법입니다.
// a 및 b에 각각 행과 열의 인덱스를 저장합니다.
// 이러한 수정으로 코드는 주어진 2D 배열에서 최댓값을 찾고 해당 값을 포인터를 통해 반환하며, 최댓값을 가진 요소의 행 및 열 인덱스도 반환합니다.

// submitted code
//  int *mmax(int n, int m, int *x, int *a, int *b)
//  {
//      int max = *x;
//      int *maxptr = x;
//      for (int q = 0; q < n; q++)
//      {
//          for (int z = 0; z < m; z++)
//          {
//              if (max < *(x + q * SIZE + z))
//              {
//                  max = *(x + q * SIZE + z);
//                  maxptr = (x + q * SIZE + z);
//                  *a = q;
//                  *b = z;
//              }
//          }
//      }
//      return maxptr;
//  }