#include <stdio.h>
#include <stdlib.h>
#include "header.h"
void push(stack **alpha, int data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = data;
    temp->next = *alpha;    
    *alpha = temp;
}
int pop(stack **alpha)
{
    if((*alpha)==NULL)
    return -1;
    stack *temp = *alpha;
    int ans=temp->data;
    *alpha = (*alpha)->next;
    free(temp);
    return ans;
}

void SwapTouple(Touple *t1, Touple *t2){
    Touple temp;
    temp.a = t1->a;
    temp.b = t1->b;
    temp.keyvalue = t1->keyvalue;

    t1->a = t2->a;
    t1->b = t2->b;
    t1->keyvalue = t2->keyvalue;

    t2->a = temp.b;
    t2->b = temp.b;
    t2->keyvalue = temp.keyvalue;
}


PtrQueueNode NewQueueNode(int element)
{
    PtrQueueNode Q = (PtrQueueNode)malloc(sizeof(StrQueueNode));
    Q->num = element;
    Q->next = NULL;
    return Q;
}

PQueue InitializePQueue(){
    PQueue pq;
    pq = malloc(sizeof(struct PriorityQueue));
    pq->size = 1;
    pq->maxIndex = 0;
    pq->arr = (Touple*)calloc(pq->size ,sizeof(Touple));

    return pq;
}

void EnquePQueue(PQueue pq, int a, int b, int value){

    if(pq->maxIndex==pq->size){
        pq->size = (pq->size)<<1;
        pq->arr = realloc(pq->arr, pq->size*sizeof(Touple));
    
    }

    pq->arr[pq->maxIndex].a = a;
    pq->arr[pq->maxIndex].b = b;
    pq->arr[pq->maxIndex].keyvalue = value;
    pq->maxIndex++;

    SiftUpPQueue(pq, pq->maxIndex - 1);
}

void SiftUpPQueue(PQueue pq, int index){
    int parent = (index-1)/2;

    if(pq->arr[parent].keyvalue>pq->arr[index].keyvalue){
        
        /* Touple temp;
        temp.a = pq->arr[parent].a;
        temp.b = pq->arr[parent].b;
        temp.keyvalue = pq->arr[parent].keyvalue;

        pq->arr[parent].a = pq->arr[index].a;
        pq->arr[parent].b = pq->arr[index].b;
        pq->arr[parent].keyvalue = pq->arr[index].keyvalue;

        pq->arr[index].a = temp.a;
        pq->arr[index].b = temp.b;
        pq->arr[index].keyvalue = temp.keyvalue; */
        
        SwapTouple(&(pq->arr[parent]), &(pq->arr[index]));
        SiftUpPQueue(pq, parent);
    }
}

void MinHeapify(PQueue pq, int index){
    int l = index;
    int r = index;

    if((2*index+1) < pq->maxIndex)
        l = 2*index + 1;
    
    if((2*index+2) < pq->maxIndex)
        r = 2*index + 2;
    
    int smallest = index;

    if(pq->arr[l].keyvalue < pq->arr[smallest].keyvalue)
        smallest = l;

    if(pq->arr[r].keyvalue < pq->arr[smallest].keyvalue)
        smallest = r;
    
    if(smallest!=index){
        SwapTouple(&(pq->arr[smallest]), &(pq->arr[index]));
        MinHeapify(pq, smallest);
    }
}

Touple PopMin(PQueue pq){
    Touple temp = pq->arr[0];
    int vscodeisdumb = pq->maxIndex;
    SwapTouple(&(pq->arr[0]), &(pq->arr[vscodeisdumb-1]));

    pq->maxIndex--;

    MinHeapify(pq, 0);  

    return temp;
}

PtrQueue CreateQueue() // Creates an empty queue
{
    PtrQueue pq = (PtrQueue)malloc(sizeof(StrQueue));
    pq->front = NULL;
    pq->rear = NULL;
}

void Enqueue(PtrQueue q, int element) // It adds an element to the queue from the rear side
{
    PtrQueueNode x = NewQueueNode(element);

    if (q->rear == NULL) // If the queue is empty
    {
        q->front = x;
        q->rear = x;
    }

    else                 // If the queue is not empty
    {
        q->rear->next = x;
        q->rear = x;
    }
}

int Dequeue(PtrQueue q)  // It deletes an element from the queue(from the front side)
{
    if (q->front != NULL)   // If the queue is not empty
    {
        PtrQueueNode x = q->front;

        int i = x->num;

        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        free(x);           // Frees that node

        return i;
    }

    else
        return -1;
}

int IsEmpty(PtrQueue q)  // It checks whether the queue is empty
{
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}
