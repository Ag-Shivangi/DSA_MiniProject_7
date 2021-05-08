#ifndef __STACK
#define __STACK
typedef struct stack
{
    struct stack *next;
    int data;
} stack;
void push(stack **alpha, int data);
int pop(stack **alpha);
#endif