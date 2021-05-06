#include <stdlib.h>

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
