#ifndef __BFS_H
#define __BFS_H

#include "graph.h"

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
void bfs(Graph* g, int begin);

#endif
