#include "graph.h"

Graph CreateGraph(int size){
	Graph resultGraph;

	resultGraph.numVertices = size;
	resultGraph.Head = (GraphNode*)malloc(size*sizeof(GraphNode));
	resultGraph.visitedDFS = (int*)calloc(resultGraph.numVertices, sizeof(int));	

	for(int i=0;i<size;i++){
		resultGraph.Head[i].numEdges = 0;
		resultGraph.Head[i].maxSize = 1;
		resultGraph.Head[i].parent = (int*)malloc(sizeof(int));
		resultGraph.Head[i].EdgeLen = (int*)malloc(sizeof(int));
		resultGraph.Head[i].vertexID = i;
	}
	
	return resultGraph;
}

void CreateEdge(Graph g, int v1, int v2, int edgelen){
	
	if(g.Head[v1].maxSize == g.Head[v1].numEdges ){
		g.Head[v1].maxSize *= 2;
		g.Head[v1].parent = (int*)realloc(g.Head[v1].parent ,g.Head[v1].maxSize*sizeof(int));
		g.Head[v1].EdgeLen = (int*)realloc(g.Head[v1].EdgeLen ,g.Head[v1].maxSize*sizeof(int));
	}

	g.Head[v1].parent[g.Head[v1].numEdges] = v2;
	g.Head[v1].EdgeLen[g.Head[v1].numEdges] = edgelen;
	g.Head[v1].numEdges++;
}

void PrintGraph(Graph g){
	for(int i=0;i<g.numVertices;i++){

		if(g.Head[i].numEdges==0)
			continue;
		printf("%d : ", i);

		for(int j=0;j<g.Head[i].numEdges;j++){
			printf("%d ", g.Head[i].parent[j]);
		}
		
		printf("\n");
	}
}

int* DjikstraAlgo(Graph g, GraphNode ref){
	PQueue internal;
	internal = InitializePQueue();

	int* distance = malloc(g.numVertices*sizeof(int));

	for(int i=0;i<g.numVertices;i++)
		distance[i] = 1000000000;
	
	distance[ref.vertexID] = 0;

	for(int i=0;i<ref.numEdges;i++){
		distance[ref.parent[i]] = ref.EdgeLen[i];
		EnquePQueue(internal, ref.vertexID, ref.parent[i], ref.EdgeLen[i]);
	}

	while(internal->maxIndex>0){
		Touple temp = PopMin(internal);

		int vertex, currdist;

		vertex = temp.b;
		currdist = temp.keyvalue;

		g.visitedDFS[vertex] = 1;
		for(int i=0;i<g.Head[vertex].numEdges;i++){
			if(g.visitedDFS[g.Head[vertex].parent[i]]!=0)
				continue;

			int dist = currdist + g.Head[vertex].EdgeLen[i];

			if(dist<distance[g.Head[vertex].parent[i]]){
				distance[g.Head[vertex].parent[i]] = dist;
				EnquePQueue(internal, vertex, g.Head[vertex].parent[i], dist);
			}
		}		
	}
	free(internal->arr);
	free(internal);
	return distance;
}
