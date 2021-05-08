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
int pop(node *alpha)
{
    if(alpha=NULL)
    return -1;
    node *temp = alpha;
    int ans=temp->data;
    alpha = alpha->next;
    free(temp);
    return ans;
}