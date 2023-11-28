#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long long_t;
typedef struct _node *node_ptr;

struct _node
{
    long_t num;
    node_ptr next;
};

node_ptr collatz(long_t n);
void clean(node_ptr head);

int main()
{
    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        long_t m;
        scanf("%lld\n", &m);
        node_ptr head = collatz(m);
        for (node_ptr t = head; t != NULL; t = t->next)
            printf("%lld ", t->num);
        printf("\n");
        clean(head);
    }
    printf("finished");
}

node_ptr collatz(long_t n)
{
    node_ptr head = NULL;
    node_ptr trail = NULL;

    while (1)
    {
        node_ptr new_node = (node_ptr)malloc(sizeof(struct _node));
        new_node->num = n;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            trail = head;
        }
        else
        {
            trail->next = new_node;
            trail = trail->next;
        }

        if (n == 1)
        {
            return head;
        }
        else if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
}

void clean(node_ptr head)
{
    while (head != NULL)
    {
        node_ptr temp = head;
        head = head->next;
        free(temp);
    }
}