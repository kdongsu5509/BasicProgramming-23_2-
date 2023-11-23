#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct _coord coord_t;
struct _coord
{
    int x;
    int y;
};

coord_t points[MAX_SIZE];

int compare(const void *a, const void *b);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    qsort(points, n, sizeof(coord_t), compare);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", points[i].x, points[i].y);
}
int compare(const void *a, const void *b)
{
    coord_t *ein = (coord_t *)a;
    coord_t *zwei = (coord_t *)b;
    if (ein->x == zwei->x)
    {
        return zwei->y - ein->y;
    }
    else
    {
        return ein->x - zwei->x;
    }
}
