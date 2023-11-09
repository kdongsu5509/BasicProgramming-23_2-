#include <stdio.h>

typedef struct _coord coord_t;

struct _coord
{
    int x;
    int y;
};

int farpoints(int n, coord_t *p, coord_t **r, coord_t **s);

int main()
{
    int n;
    scanf("%d", &n);
    coord_t point[100];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &point[i].x, &point[i].y);
    coord_t *u, *v;
    int sqrdist = farpoints(n, point, &u, &v);
    printf("sqrt(%d)\n", sqrdist);
    printf("%d %d\n", u->x, u->y);
    printf("%d %d\n", v->x, v->y);
}

int farpoints(int n, coord_t *p, coord_t **r, coord_t **s)
{
    int maxSqrdist = 0;
    *r = NULL;
    *s = NULL;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = p[i].x - p[j].x;
            int dy = p[i].y - p[j].y;
            int sqrdist = dx * dx + dy * dy;

            if (sqrdist > maxSqrdist)
            {
                maxSqrdist = sqrdist;
                *r = &p[i];
                *s = &p[j];
            }
        }
    }

    return maxSqrdist;
}
