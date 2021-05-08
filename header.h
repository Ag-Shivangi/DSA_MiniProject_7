#ifndef __STACK
#define __STACK
#include <stdlib.h>
typedef struct stack
{
    struct stack *next;
    int data;
} stack;
void push(stack **alpha, int data);
int pop(stack **alpha);


typedef int id_type;
typedef struct touplenode {
    //id_type keyid;
    int a;
    int b;
    int keyvalue;
}   Touple;

typedef struct PriorityQueue {
    Touple *arr;
    int size;
    int maxIndex;
} *PQueue;

PQueue InitializePQueue();
void EnquePQueue(PQueue pq, int a, int b, int value);
void SiftUpPQueue(PQueue pq, int index);
Touple PopMin(PQueue pq);
typedef struct Queue StrQueue;
typedef StrQueue* PtrQueue;
typedef struct QueueNode StrQueueNode;
typedef StrQueueNode* PtrQueueNode;

struct QueueNode
{
    int num;
    PtrQueueNode next;
};

struct Queue
{
    PtrQueueNode front;
    PtrQueueNode rear;
};

PtrQueueNode NewQueueNode(int element);
PtrQueue CreateQueue();
void Enqueue(PtrQueue q, int element);
int Dequeue(PtrQueue q);
int IsEmpty(PtrQueue q);
#endif