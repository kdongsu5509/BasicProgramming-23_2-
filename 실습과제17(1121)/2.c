#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node node_t;

struct _node
{
    char name[20];
    int price;
    node_t *next;
};

node_t *head = NULL;

node_t *create_node(char *name, int price);
void append_node(node_t *node);
node_t *find_largest();

int main()
{
    int n;
    scanf("%d\n", &n);
    char str[20];
    int price;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d\n", str, &price);
        node_t *ptr = create_node(str, price);
        if (head == NULL)
            head = ptr;
        else
            append_node(ptr);
    }
    node_t *largest = find_largest();
    printf("%s %d", largest->name, largest->price);

    // 메모리 해제 추가
    node_t *current = head;
    while (current != NULL)
    {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

node_t *create_node(char *name, int price)
{
    node_t *newnode = (node_t *)malloc(sizeof(struct _node));
    newnode->price = price;
    strcpy(newnode->name, name);
    newnode->next = NULL; // 노드 초기화 시 next를 NULL로 설정
    return newnode;
}

void append_node(node_t *node)
{
    node_t *cursor = head;
    while (cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    cursor->next = node;
}

node_t *find_largest()
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

    return largest;
}
