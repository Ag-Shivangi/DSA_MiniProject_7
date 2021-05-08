#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

PtrQueueNode NewQueueNode(int element)
{
    PtrQueueNode Q = (PtrQueueNode)malloc(sizeof(StrQueueNode));
    Q->num = element;
    Q->next = NULL;
    return Q;
}

PtrQueue CreateQueue()
{
    PtrQueue pq = (PtrQueue)malloc(sizeof(StrQueue));
    pq->front = NULL;
    pq->rear = NULL;
}

void Enqueue(PtrQueue q, int element)
{
    PtrQueueNode x = NewQueueNode(element);

    if (q->rear == NULL)
    {
        q->front = x;
        q->rear = x;
    }

    else
    {
        q->rear->next = x;
        q->rear = x;
    }
}

int Dequeue(PtrQueue q)
{
    if (q->front != NULL)
    {
        PtrQueueNode x = q->front;

        int i = x->num;

        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        free(x);

        return i;
    }

    else
        return -1;
}

int IsEmpty(PtrQueue q)
{
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

