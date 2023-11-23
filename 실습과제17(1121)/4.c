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
        scanf("%19s %d\n", str, &price);
        node_t *ptr = create_node(str, price);
        append_node(&head, ptr);
    }
    node_t *second = find_second(head);
    if (second != NULL)
        printf("%s %d", second->name, second->price);

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

node_t *find_second(node_t *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    node_t *largest = head;
    node_t *second = head->next;

    while (head != NULL)
    {
        if (head->price > largest->price)
        {
            second = largest;
            largest = head;
        }
        else if (head->price > second->price && head->price != largest->price)
        {
            second = head;
        }
        head = head->next;
    }

    return second;
}

// 디버깅 많이 살 길이다. -> 왜 1시간을 해매게 하였는지 찾아라
