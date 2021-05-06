#include <stdio.h>
#include <stdlib.h>

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

    if(q->rear == NULL)
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
    if(q->front != NULL)
    {
        PtrQueueNode x = q->front;

        int i = x->num;

        q->front = q->front->next;

        if(q->front == NULL)
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
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

void bfs(struct Graph* g, int begin)
{
    int n = 0;

    int x = g->vertices;

    int visited[x];

    for(int i = 0; i < x; i++)
    {
        visited[i] = 0;
    }

    PtrQueue q = CreateQueue();

    Enqueue(q, begin);

    while(IsEmpty(q) != 1 && n <= 10)
    {
        int top = Dequeue(q);

        visited[top] = 1;

        n++;
        
        printf("%d\n", top);

        struct GraphNode* x = g->list[top];

        while(x != NULL)
        {
            int adjacent = x->vertex;

            if(visited[adjacent] == 0)
            {
                visited[adjacent] = -1;
                Enqueue(q, adjacent);
            }
            x = x->next;
        }
    }
}

PtrGraphNode NewGraphNode(int vertex)
{
    PtrGraphNode gn = (PtrGraphNode)malloc(sizeof(StrGraphNode));
    gn->vertex = vertex;
    gn->next = NULL;
    return gn;
}

PtrGraph CreateGraph(int num)
{
    PtrGraph g = (PtrGraph)malloc(sizeof(StrGraph));
    g->vertices = num;
    g->list = (PtrGraphNode*)malloc(num * sizeof(PtrGraphNode));
    for(int i = 0; i < num; i++)
    {
        g->list[i] = NULL;
    }

    return g;
}

void InsertEdge(PtrGraph g, int start, int end)
{
    PtrGraphNode x = NewGraphNode(end);
    x->next = g->list[start];
    g->list[start] = x;

    PtrGraphNode y = NewGraphNode(start);
    y->next = g->list[end];
    g->list[end] = y;
}