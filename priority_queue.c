#include "priority_queue.h"

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
