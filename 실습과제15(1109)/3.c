#include <stdio.h>

typedef struct _fruit fruit_t;

struct _fruit
{
    int price;
    char name[100];
};

fruit_t *find_both(int n, fruit_t *items, fruit_t **maxptr);

int main()
{
    fruit_t fruits[20];
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", fruits[i].name, &fruits[i].price);

    fruit_t *maxptr, *sndptr;
    sndptr = find_both(n, fruits, &maxptr);
    printf("%s %d\n", maxptr->name, maxptr->price);
    printf("%s %d\n", sndptr->name, sndptr->price);
}
////
fruit_t *find_both(int n, fruit_t *items, fruit_t **maxptr)
{
    // 구조체 주소 반환
    int max_price = items->price;
    *maxptr = items;
    fruit_t *ptr = items;
    for (int i = 0; i < n; i++)
    {
        if (max_price < (*(items + i)).price)
        {
            max_price = (*(items + i)).price;
            *maxptr = items + i;
            ptr = items + i;
        }
    }

    int temp = ptr->price;
    ptr->price = 0;

    max_price = items->price;
    fruit_t *ptr2 = items;
    for (int i = 0; i < n; i++)
    {
        if (max_price < (*(items + i)).price)
        {
            max_price = (*(items + i)).price;
            ptr2 = items + i;
        }
    }
    ptr->price = temp;

    return ptr2;
}