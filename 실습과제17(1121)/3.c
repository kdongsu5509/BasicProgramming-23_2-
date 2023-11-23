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

node_t *create_node(const char *name, int price);
void append_node(node_t **head, node_t *node);
node_t *find_second(node_t *head);

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
    node_t *second = find_second(head);
    printf("%s %d\n", second->name, second->price);

    // 메모리 해제
    node_t *current = head;
    while (current != NULL)
    {
        node_t *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }

    return 0;
}

node_t *create_node(const char *name, int price)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if (newnode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // 문자열을 복사하기 위해 메모리 할당 후 문자열 복사
    newnode->name = (char *)malloc(strlen(name) + 1);
    if (newnode->name == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newnode->name, name);

    newnode->price = price;
    newnode->next = NULL;

    return newnode;
}

void append_node(node_t **head, node_t *node)
{
    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        node_t *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = node;
    }
}

node_t *find_second(node_t *head)
{
    node_t *temp = head;
    node_t *largest = head;

    while (temp != NULL)
    {
        if (temp->price > largest->price)
        {
            largest = temp;
        }
        temp = temp->next;
    }

    // 두 번째로 큰 값을 찾기 위해 초기화
    temp = head;
    node_t *zwei = head;
    node_t *second = head;

    while (zwei != NULL)
    {
        if (zwei->price > second->price && zwei->price != largest->price)
        {
            second = zwei;
        }
        zwei = zwei->next;
    }

    return second;
}
