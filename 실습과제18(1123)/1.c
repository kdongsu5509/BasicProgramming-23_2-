#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node_t;

struct _node
{
    char *name;
    int price;
    node_t *next;
};

node_t *create_node(char *name, int price);
void append_node(node_t **head, node_t *node);
void bubblesort(int n, node_t *head);

int main()
{
    int n;
    scanf("%d\n", &n);
    char str[20];
    int price;
    node_t *head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d\n", str, &price);
        node_t *ptr = create_node(str, price);
        append_node(&head, ptr);
    }
    bubblesort(n, head);
    node_t *trail = head;
    while (trail != NULL)
    {
        printf("%s %d\n", trail->name, trail->price);
        trail = trail->next;
    }
}

node_t *create_node(char *name, int price)
{
    // 동적으로 노드 할당
    node_t *new_node = (node_t *)malloc(sizeof(struct _node));

    // 동적으로 문자열 할당 및 복사
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);

    // 나머지 필드 초기화
    new_node->price = price;
    new_node->next = NULL;

    // 생성된 노드의 주소 반환
    return new_node;
}
void append_node(node_t **head, node_t *node)
{
    node_t *temp = *head;

    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
void bubblesort(int n, node_t *head)
{
    // n은 개수 / head-> 스타트 포인트
    for (int i = 0; i < n - 1; i++)
    {
        node_t *temp_ptr = head;
        node_t *prev = NULL;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (temp_ptr->price < temp_ptr->next->price)
            {
                // 가격 교환
                int store = temp_ptr->price;
                temp_ptr->price = temp_ptr->next->price;
                temp_ptr->next->price = store;

                // 이름 교환
                char *name_store = temp_ptr->name;
                temp_ptr->name = temp_ptr->next->name;
                temp_ptr->next->name = name_store;
            }
            prev = temp_ptr;
            temp_ptr = temp_ptr->next;
        }
    }
}