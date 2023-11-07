#include <stdio.h>

void find_both(int n, int *arr, int *maxptr, int *minptr)
{
    int maxval = *arr;
    int minval = *arr;
    for (int a = 0; a < n; a++)
    {
        if (maxval < *(arr + a))
        {
            maxval = *(arr + a);
            maxptr = (arr + a);
        }
        for (int a = 0; a < n; a++)
        {
            if (minval > *(arr + a))
            {
                minval = *(arr + a);
                minptr = (arr + a);
            }
        }
    }
}

int main()
{
    int bae[5] = {1, 2, 3, 4, 5};
    int largest = 0, smallest = 10;
    find_both(5, bae, &largest, &smallest);
    printf("%d %d", largest, smallest);

    return 0;
}