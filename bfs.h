#ifndef __BFS_H
#define __BFS_H

typedef struct Queue StrQueue;
typedef StrQueue* PtrQueue;
typedef struct QueueNode StrQueueNode;
typedef StrQueueNode* PtrQueueNode;
typedef struct Graph StrGraph;
typedef StrGraph* PtrGraph;
typedef struct GraphNode StrGraphNode;
typedef StrGraphNode* PtrGraphNode;

struct Graph {
    int vertices;
    PtrGraphNode* list;
};

struct GraphNode {
    int vertex;
    PtrGraphNode next;
};

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
void bfs(struct Graph* g, int begin);
PtrGraphNode NewGraphNode(int vertex);
PtrGraph CreateGraph(int num);
void InsertEdge(PtrGraph g, int start, int end);

#endif