#include "graph.h"
#include "header.h"

Graph CreateGraph(int size){//Creates the intial graph
	Graph resultGraph;

	resultGraph.numVertices = size;
	resultGraph.Head = (GraphNode*)malloc(size*sizeof(GraphNode));
	resultGraph.visitedDFS = (int*)calloc(resultGraph.numVertices, sizeof(int));	

	for(int i=0;i<size;i++){
		resultGraph.Head[i].numEdges = 0;
		resultGraph.Head[i].maxSize = 1;
		resultGraph.Head[i].parent = (int*)malloc(sizeof(int));
		resultGraph.Head[i].EdgeLen = (int*)malloc(sizeof(int));
		
		resultGraph.Head[i].no_followers = 0;
		resultGraph.Head[i].maxSize_follower = 1;
		resultGraph.Head[i].follower = (int*)malloc(sizeof(int));
		resultGraph.Head[i].userExistence = 0;
		//resultGraph.Head[i].vertexID = i;
	}
	
	return resultGraph;
}

void StartFollowing(Graph g, int v1, int v2){	//v1 starts following v2
	if(g.Head[v1].maxSize == g.Head[v1].numEdges ){//resizes the array of parent if the size exceeds
		g.Head[v1].maxSize *= 2;
		g.Head[v1].parent = (int*)realloc(g.Head[v1].parent ,g.Head[v1].maxSize*sizeof(int));
		g.Head[v1].EdgeLen = (int*)realloc(g.Head[v1].EdgeLen ,g.Head[v1].maxSize*sizeof(int));
	}
    
	g.Head[v1].parent[g.Head[v1].numEdges] = v2;
	g.Head[v1].EdgeLen[g.Head[v1].numEdges] = 1;
	g.Head[v1].numEdges++;

	if(g.Head[v2].maxSize_follower == g.Head[v2].no_followers ){ //updating the followers list of v2, and resizing the array
		g.Head[v2].maxSize_follower *= 2;
		g.Head[v2].follower = (int*)realloc(g.Head[v1].follower ,g.Head[v1].maxSize_follower*sizeof(int));
		//g.Head[v1].EdgeLen = (int*)realloc(g.Head[v1].EdgeLen ,g.Head[v1].maxSize*sizeof(int));
	}	

	g.Head[v2].follower[g.Head[v2].no_followers] = v1;
	g.Head[v2].no_followers++;

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

void DeleteVertex(Graph g, int vertex){
	for(int k=0;k<g.Head[vertex].maxSize_follower;k++){
		int index = -1;
		
		int i = g.Head[vertex].follower[k];
		
		for(int j=0;j<g.Head[i].numEdges;j++){
			if(g.Head[i].parent[j]==vertex){
				index = j;
			}
		}

		if(index!=-1)
			for(int j=index+1;j<g.Head[i].numEdges;j++)
				g.Head[i].parent[j-1] = g.Head[i].parent[j];  
	}
	
	free(g.Head[vertex].EdgeLen);
	free(g.Head[vertex].parent);

	g.Head[vertex].numEdges = 0;
	g.Head[vertex].maxSize = 1;	

	g.Head[vertex].parent = (int*)malloc(sizeof(int));
	g.Head[vertex].EdgeLen = (int*)malloc(sizeof(int));

}


int DjikstraAlgoModified(Graph g, GraphNode ref, int userID){
	PQueue internal;
	internal = InitializePQueue();

	int* distance = malloc(g.numVertices*sizeof(int));

	for(int i=0;i<g.numVertices;i++)
		distance[i] = INT_MAX;
	
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

		if(vertex == userID){
			free(internal->arr);
			free(internal);
			return distance[userID];
		}
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
	return INT_MAX;
}



void resize_graph(Graph* g){
	int temp = g->numVertices;
	g->numVertices*=2;
	g->Head = realloc(g->Head, g->numVertices*sizeof(GraphNode));

	for(int i=temp;i<g->numVertices;i++){
		g->Head[i].numEdges = 0;
		g->Head[i].maxSize = 1;
		g->Head[i].parent = (int*)malloc(sizeof(int));
		g->Head[i].EdgeLen = (int*)malloc(sizeof(int));
		g->Head[i].userExistence = 0;		
		g->Head[i].no_followers = 0;
		g->Head[i].maxSize_follower = 1;
		g->Head[i].follower = (int*)malloc(sizeof(int));		
	}
}

void LookUpUser(Graph g,int currID ,int userID){

	int check = DjikstraAlgoModified(g, g.Head[currID], userID);

	if(check!=INT_MAX)
		printf("%d is a %d degree friend\n", userID, check);
		
	printf("Name of user : %s", g.Head[userID].name);
	printf("City of location of user: %s", g.Head[userID].city);
}

void RemoveEdge(Graph g, int v1, int v2){	//v2 is removed from follow list of v1, as in v1 is not following v2 anymore

	int index = -1;
		
	for(int j=0;j<g.Head[v1].numEdges;j++){
		if(g.Head[v1].parent[j]==v2){
			index = j;
		}
	}

	if(index!=-1)
		for(int j=index+1;j<g.Head[v1].numEdges;j++)
			g.Head[v1].parent[j-1] = g.Head[v1].parent[j];  

}