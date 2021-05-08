#ifndef _GRAPH_STUFF_
#define _GRAPH_STUFF_

#include <stdio.h>
#include <stdlib.h>
typedef struct GraphNode {
	int vertexID;
	int *parent; //array containing people it's following ig.
	int *EdgeLen; 
	int numEdges; //number of the people it's follwing.
	int maxSize; //current allocatedd maximum size of the parent arr
	//apologies for the confusion caused in the naming
	int no_followers;
    int *follower; //self explanatory i think
	int maxSize_follower;


	char name[30];
    char city[30];
    char password[21];
    //birthday details
    int date;
    int month;
    int year;
    //add user hobby

    //int no_following;
    //int *following;


} GraphNode;

typedef struct ActualGraph {
	struct GraphNode *Head;
	int numVertices;
	int *visitedDFS;
}	Graph;

Graph CreateGraph(int size);
void CreateEdge(Graph g, int v1, int v2, int edgelen);
void PrintGraph(Graph g);

#endif



