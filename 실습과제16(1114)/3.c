// 과일가게 정렬//
/*길이의 오름차순
길이가 같으면 이름의 오름차순
이름도 같으면 가격의 내림차순*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct _fruit fruit_t;
struct _fruit
{
    char name[20];
    int price;
};

fruit_t fruits[MAX_SIZE];

int compare(const void *a, const void *b);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s %d", fruits[i].name, &fruits[i].price);
    qsort(fruits, n, sizeof(fruit_t), compare);
    printf("%s\n", "----------------------------------------------------");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", fruits[i].name, fruits[i].price);
}

int compare(const void *a, const void *b)
{
    // 1. 오름차순 정렬 -> 이름 길이
    fruit_t *x = (fruit_t *)a;
    fruit_t *y = (fruit_t *)b;

    if (strlen(x->name) != strlen(y->name))
    {
        return strlen(x->name) - strlen(y->name);
    }
    // 2.이름 알파벳 오름차순
    int nameCompare = strcmp(x->name, y->name);
    if (nameCompare != 0)
    {
        return nameCompare;
    }
    // 3.가격 오름차순
    return y->price - x->price;
}