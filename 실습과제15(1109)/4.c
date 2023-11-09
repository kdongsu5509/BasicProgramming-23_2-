// void bubblesort(int n, char *s)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (*(s + j) > *(s + j + 1))
//                 swap(s, j, j + 1);
//         }
//     }
// }

#include <stdio.h>

typedef struct _coord coord_t;

struct _coord
{
    int x;
    int y;
};

void bubblesort(int n, coord_t *point);
int compare(coord_t x, coord_t y);
void swap(coord_t *x, coord_t *y);

int main()
{
    int n;
    scanf("%d", &n);
    coord_t point[100];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &point[i].x, &point[i].y);
    bubblesort(n, point);
    printf("________________________________________________________________\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", point[i].x, point[i].y);
}

void bubblesort(int n, coord_t *point)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (compare((*(point + j)), (*(point + (j + 1)))) > 0)
                swap(point + j, point + j + 1);
}

int compare(coord_t x, coord_t y)
{
    // 좌표값을 직접 받아서 비교한다.
    if (x.x == y.x)
    {
        if (x.y >= y.y)
        {
            return -1; // Corrected part
        }
        else
        {
            return 1;
        }
    }

    else if (x.x > y.x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void swap(coord_t *x, coord_t *y)
{
    coord_t temp = *x;
    *x = *y;
    *y = temp;
}