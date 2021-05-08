#include "struct.h"
array_hobby list_hobbies[8]; //stores hobby names
stack *next_id;
void initialise() //all initalisation goes here
{
	push(&next_id, 0);
	init_hobby();
}
Graph CreateGraph(int size) //Creates the intial graph
{
	Graph resultGraph;

	resultGraph.numVertices = size;
	resultGraph.Head = (GraphNode *)malloc(size * sizeof(GraphNode));
	resultGraph.visitedDFS = (int *)calloc(resultGraph.numVertices, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		resultGraph.Head[i].numEdges = 0;
		resultGraph.Head[i].maxSize = 10;
		resultGraph.Head[i].parent = (int *)malloc(1 * sizeof(int));
		resultGraph.Head[i].EdgeLen = (int *)malloc(sizeof(int));

		resultGraph.Head[i].no_followers = 0;
		resultGraph.Head[i].maxSize_follower = 1;
		resultGraph.Head[i].follower = (int *)malloc(sizeof(int));
		//resultGraph.Head[i].vertexID = i;
	}

	return resultGraph;
}
void StartFollowing(Graph g, int v1, int v2)
{												   //v1 starts following v2
	if (g.Head[v1].maxSize == g.Head[v1].numEdges) //resizes the array of parent if the size exceeds
	{
		g.Head[v1].maxSize *= 2;
		g.Head[v1].parent = (int *)realloc(g.Head[v1].parent, g.Head[v1].maxSize * sizeof(int));
		g.Head[v1].EdgeLen = (int *)realloc(g.Head[v1].EdgeLen, g.Head[v1].maxSize * sizeof(int));
	}

	g.Head[v1].parent[g.Head[v1].numEdges] = v2; //adding to the parent list
	g.Head[v1].EdgeLen[g.Head[v1].numEdges] = 1;
	g.Head[v1].numEdges++;

	if (g.Head[v2].maxSize_follower == g.Head[v2].no_followers) //updating the followers list of v2\
	                                                            and resizing the array
	{
		g.Head[v2].maxSize_follower *= 2;
		g.Head[v2].follower = (int *)realloc(g.Head[v1].follower, g.Head[v1].maxSize_follower * sizeof(int));
		//g.Head[v1].EdgeLen = (int*)realloc(g.Head[v1].EdgeLen ,g.Head[v1].maxSize*sizeof(int));
	}

	g.Head[v2].follower[g.Head[v2].no_followers] = v1;
	g.Head[v2].no_followers++;
}
void choose_hobby(int a) //function which genereates a boolean string in int form of the hobbies choosen                        
{
	a = 0;
	int count[8] = {};
	char choosen[25];
	scanf("%s", choosen);
	fo(i, strlen(choosen))
	{
		if (choosen[i] != ',')
		{
			count[choosen[i] - '1'] = 1;
		}
	}
	fo(i, 8)
	{
		a = a + pow(10, count[i]);
	}
}
void create_user(Graph g) //reads and stores the data of the user
{

	int id = pop(&next_id);
	if (id == -1)
	{
		resize_graph(&g);
	}
	push(&next_id, id + 1);
	printf("Enter you name : \n");
	scanf("%s", g.Head[id].name);
	printf("Enter your city : \n");
	scanf("%s", g.Head[id].city);
	printf("Enter you birthday (format: dd/mm/yyyy): \n");
	scanf("%d/%d/%d", &g.Head[id].date, &g.Head[id].month, &g.Head[id].year);
	printf("Enter you choice of hobbies (x,y,z):\n");
	printf("1) Painting\n");
	printf("2) Dance\n");
	printf("3) Music\n");
	printf("4) Cricket\n");
	printf("5) Football\n");
	printf("6) Gaming\n");
	printf("7) Anime\n");
	printf("8) Programming\n");
	choose_hobby(g.Head[id].hobbies);
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
void hobby_recommend();
bfs(Graph g, int begin, int array[])
{
	int n = 0; //keeps a count od t

	int x = *(g.numVertices); //number of vertices

	int visited[x];

	for (int i = 0; i < x; i++)
	{
		visited[i] = 0;
	}
	GraphNode temp = g.Head[begin];

	int t = temp.numEdges;
	int l = t;
	while (t != 0)
	{
		int adjacent = temp.parent[l - t];
		visited[adjacent] =1;		
		t--;
	}
	PtrQueue q = CreateQueue();

	Enqueue(q, begin);

	while (IsEmpty(q) != 1 && n <= 10)
	{
		int top = Dequeue(q);

		visited[top] = 1;

		n++;

		GraphNode temp = g.Head[top];

		int t = temp.numEdges;
		int l = t;

		while (t != 0)
		{
			int adjacent = temp.parent[l - t];

			if (visited[adjacent] == 0)
			{
				visited[adjacent] = -1;
				Enqueue(q, adjacent);
			}
			t--;
		}
	}
}

void recommendations(Graph g, int id)
{
	int friends[10];
	if (g.Head[id].numEdges == 0)
	{
        hobby_recommend(g,id);
	}
	
}
void display_details()
{
}
void update_details()
{
}
int main()
{
	Graph alpha;
	alpha = CreateGraph(10);
}
