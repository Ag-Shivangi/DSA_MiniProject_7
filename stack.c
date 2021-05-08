#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    struct node *next;
    int data;
} stack;
void push(stack *alpha, int data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = data;
    temp->next = NULL;
    alpha = temp;
}
int pop(stack *alpha)
{
    if(alpha=NULL)
    return -1;
    stack *temp = alpha;
    int ans=temp->data;
    alpha = alpha->next;
    free(temp);
    return ans;
}