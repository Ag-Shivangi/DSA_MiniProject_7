#include "struct.h"
array_hobby list_hobbies[8]; //stores hobby names
stack *next_id;
Graph CreateGraph(int size)//Creates the intial graph
{
	Graph resultGraph;

	resultGraph.numVertices = size;
	resultGraph.Head = (GraphNode *)malloc(size * sizeof(GraphNode));
	resultGraph.visitedDFS = (int *)calloc(resultGraph.numVertices, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		resultGraph.Head[i].numEdges = 0;
		resultGraph.Head[i].maxSize = 10;
		resultGraph.Head[i].parent = (int *)malloc(1*sizeof(int));
		resultGraph.Head[i].EdgeLen = (int *)malloc(sizeof(int));

		resultGraph.Head[i].no_followers = 0;
		resultGraph.Head[i].maxSize_follower = 1;
		resultGraph.Head[i].follower = (int *)malloc(sizeof(int));
		//resultGraph.Head[i].vertexID = i;
	}

	return resultGraph;
}
void StartFollowing(Graph g, int v1, int v2)
{ //v1 starts following v2
	if (g.Head[v1].maxSize == g.Head[v1].numEdges)//resizes the array of parent if the size exceeds
	{
		g.Head[v1].maxSize *= 2;
		g.Head[v1].parent = (int *)realloc(g.Head[v1].parent, g.Head[v1].maxSize * sizeof(int));
		g.Head[v1].EdgeLen = (int *)realloc(g.Head[v1].EdgeLen, g.Head[v1].maxSize * sizeof(int));
	}

	g.Head[v1].parent[g.Head[v1].numEdges] = v2;//adding to the parent list
	g.Head[v1].EdgeLen[g.Head[v1].numEdges] = 1;
	g.Head[v1].numEdges++;

	if (g.Head[v2].maxSize_follower == g.Head[v2].no_followers)//updating the followers list of v2\
	                                                            and resizing the array 
	{
		g.Head[v2].maxSize_follower *= 2;
		g.Head[v2].follower = (int *)realloc(g.Head[v1].follower, g.Head[v1].maxSize_follower * sizeof(int));
		//g.Head[v1].EdgeLen = (int*)realloc(g.Head[v1].EdgeLen ,g.Head[v1].maxSize*sizeof(int));
	}

	g.Head[v2].follower[g.Head[v2].no_followers] = v1;
	g.Head[v2].no_followers++;
}
void create_user(Graph g)
{
   int id=pop(next_id);
   printf("Enter you name : \n");
   scanf("%s",&g.Head[id].name);
   printf("Enter your city : \n");
   scanf("%s",&g.Head[id].city);
   printf("Enter you birthday (format: dd/mm/yyyy): \n");
   scanf("%d/%d/%d",&g.Head[id].date,&g.Head[id].month,&g.Head[id].year);
   

}
void init_hobby() //initialises the hobbies in the database
{
   strcpy(list_hobbies[0].hobby, "Painting");
   strcpy(list_hobbies[1].hobby, "Dance");
   strcpy(list_hobbies[2].hobby, "Music");
   strcpy(list_hobbies[3].hobby, "Cricket");
   strcpy(list_hobbies[4].hobby, "Football");
   strcpy(list_hobbies[5].hobby, "Gaming");
   strcpy(list_hobbies[6].hobby, "Anime");
   strcpy(list_hobbies[7].hobby, "Programming");
}
void choose_hobby()
{
   char choosen[30];
   scanf("%s", choosen);
   fo(i, strlen(choosen))
   {
      if (choosen[i] > 40)
      {
         
      }
   }
}
void create_user()
