#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
    int data;
} node;
void push(node *alpha, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    alpha = temp;
}
void pop(node *alpha)
{

    if (alpha != NULL)
    {
        node *temp = alpha;
        alpha = alpha->next;
        free(temp);
    }
}