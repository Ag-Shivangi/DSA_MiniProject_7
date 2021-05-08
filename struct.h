#ifndef __GRAPHS
#define __GRAPHS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
#include <crypt.h>
#include "stack.c"
#include "graph.h"
#include "graph.c"
#define fo(i, n) for (int i = 0; i < n; i++)
#define fod(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long llu;
typedef struct array_hobby
{
    char hobby[25];
} array_hobby;
typedef struct ActualGraph
{
    struct GraphNode *Head;
    int numVertices;
    int *visitedDFS;
}Graph;
typedef struct GraphNode
{
    int vertexID;
    int *parent; //array containing people it's following ig.
    int *EdgeLen;
    int numEdges; //number of the people it's follwing.
    int maxSize;  //current allocatedd maximum size of the parent arr
    //apologies for the confusion caused in the naming
    int no_followers;
    int *follower; //self explanatory i think
    int maxSize_follower;
    char name[30];
    char city[30];
   char password[35];
    //birthday details
    int date;
    int month;
    int year;

    char hobbies[10]; //boolean string
    //int no_following;
    //int *following;

} GraphNode;
#endif