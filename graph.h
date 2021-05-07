#ifndef _GRAPH_STUFF_
#define _GRAPH_STUFF_

#include <stdio.h>
#include <stdlib.h>
typedef struct GraphNode {
	int vertexID;
	int *parent;
	int *EdgeLen;
	int numEdges;
	int maxSize;
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



