// #include <stdio.h>

// typedef struct _fruit fruit_t;

// struct _fruit
// {
//     int price;
//     char name[20];
// };

// int fruit_compare(fruit_t a, fruit_t b)
// {
//     return a.price - b.price;
// }

// int main()
// {
//     fruit_t frt[3] = {{100, "apple"}, {200, "banana"}, {300, "Kiwi"}};
//     if (fruit_compare(frt[0], frt[1]) == 0)
//     {
//         printf("same\n");
//     }
//     int max_price = frt[0].price;
//     fruit_t *tpr = frt;
//     for (int i = 0; i < 3; i++)
//     {
//         if (max_price < frt[i].price)
//         {
//             max_price = frt[i].price;
//             tpr = &frt[i];
//         }
//     }
// }

#include <stdio.h>

typedef struct _fruit fruit_t;

struct _fruit
{
    int price;
    char name[100];
};

fruit_t *find_second(int n, fruit_t *items);

int main()
{
    fruit_t fruits[20];
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", fruits[i].name, &fruits[i].price);

    fruit_t *sndptr = find_second(n, fruits);
    printf("%s %d\n", sndptr->name, sndptr->price);
}

fruit_t *find_second(int n, fruit_t *items)
{
    // 구조체 주소 반환
    int max_price = items->price;
    fruit_t *ptr = items;
    for (int i = 0; i < n; i++)
    {
        if (max_price < (*(items + i)).price)
        {
            max_price = (*(items + i)).price;
            ptr = items + i;
        }
    }

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

    return ptr2;
}