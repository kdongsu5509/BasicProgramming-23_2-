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
void remove_node(node_t **head, node_t *node);
node_t *find_largest(node_t *head);

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
    for (int i = 0; i < n; i++)
    {
        node_t *largest = find_largest(head);
        printf("%s %d\n", largest->name, largest->price);
        remove_node(&head, largest);
        free(largest);
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
void remove_node(node_t **head, node_t *node_to_remove)
{
    if (*head == NULL || node_to_remove == NULL)
    {
        return;
    }

    if (*head == node_to_remove)
    {
        *head = node_to_remove->next;
    }
    else
    {
        node_t *current = *head;
        while (current->next != NULL && current->next != node_to_remove)
        {
            current = current->next;
        }

        if (current->next != NULL)
        {
            current->next = node_to_remove->next;
        }
    }
}

node_t *find_largest(node_t *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node_t *largest = head;

    while (head != NULL)
    {
        if (head->price > largest->price)
        {
            largest = head;
        }
        head = head->next;
    }

    return largest;
}
