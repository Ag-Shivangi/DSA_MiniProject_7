#include "functions.h"
#include "struct.h"
array_hobby list_hobbies[8]; //stores hobby names
stack *next_id;
hobby *hobby_graph;
hobby *make_graph(int v)
{
	hobby *temp;
	temp = (hobby *)malloc(sizeof(hobby));
	temp->v = v;
	temp->array = (ad_list *)malloc(v * sizeof(ad_list));
	fo(i, v) temp->array[i].head = NULL;
	return temp;
}
void make_edge(hobby *alpha, int e1, int e2)
{
	ad_node *temp = (ad_node *)malloc(sizeof(ad_node));
	temp->vertex = e2;
	temp->next = alpha->array[e1].head;
	alpha->array[e1].head = temp;
}
void hobby_array()
{
	hobby_graph = make_graph(256); //graph stores all the hobbies,there are 256 possibilities
}
void choose_hobby(int a[], int id) //function which genereates a boolean string in int form of the hobbies choosen
{

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
		a[i] = count[i];
	}
	int number = 0;
	fo(i, 8)
	{
		number = number + pow(2, count[i]);
	}
	make_edge(hobby_graph, number, id);
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
	choose_hobby(g.Head[id].hobbies, id);
	printf("Your Registration is complete and your assigned id is %d\n", id);
	g.Head[id].userExistence = 1;
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
void hobby_recommend(Graph g, int id, int arr[], int number)
{
	int count[256] = {};
	int temp[8];
	int n;
	fo(i, 8) if (g.Head[id].hobbies[i] == 1)
		n++;
	perm store[(int)pow(2, n)];
	fo(zi, pow(2, n))
	{
		fo(i, 8)
			temp[i] = g.Head[id].hobbies[i];
		int j = 0, m = zi, k = 0;
		while (m != 0)
		{
			store[zi].count[k] = m % 2;
			m = m / 2;
			k++;
		}
		k = 0;
		fo(i, 8)
		{
			if (temp[i] == 0)
			{
				temp[i] = store[zi].count[k];
				k++;
			}
		}
		int num = 0;
		fo(i, 8)
		{
			num = num + pow(2, temp[i]);
		}
		ad_node *point = hobby_graph->array[num].head;
		while (point != NULL)
		{
			arr[number] = point->vertex;
			number++;
			if (number > 10)
				break;
		}
	}
	int tn = 8 - n;
	if (number < 10)
	{
		fo(zi, pow(2, tn) - 1)
		{
			fo(i, 8)
				temp[i] = g.Head[id].hobbies[i];
			int j = 0, m = zi, k = 0;
			int count[n];
			while (m != 0)
			{
				count[k] = m % 2;
				m = m / 2;
				k++;
			}
			fo(li, pow(2, n))
				k = 0;
			fo(i, 8)
			{
				if (temp[i] == 1)
					temp[i] = count[k];
				else
					temp[i] = store[zi].count[k];
				k++;
			}
			int num = 0;
			int num = 0;
			fo(i, 8)
			{
				num = num + pow(2, temp[i]);
			}
			ad_node *point = hobby_graph->array[num].head;
			while (point != NULL)
			{
				arr[number] = point->vertex;
				number++;
				if (number > 10)
					break;
			}
		}
	}
}
int bfs(Graph g, int begin, int *arr)
{
	int n = 0;

	int x = g.numVertices;

	int visited[x];
	int adjvisited[x];

	for (int i = 0; i < x; i++)
	{
		visited[i] = 0;
	}

	PtrQueue q = CreateQueue();

	Enqueue(q, begin);

	GraphNode temp = g.Head[begin];

	int t = temp.numEdges;

	int l = t;

	while (t != 0)
	{
		int adjacent = temp.parent[l - t];
		adjvisited[adjacent] = 1;
		t--;
	}

	adjvisited[begin] = 1;

	while (IsEmpty(q) != 1 && n <= 10)
	{
		int top = Dequeue(q);

		visited[top] = 1;

		if (adjvisited[top] != 1)
		{
			arr[n] = top;
			n++;
		}

		GraphNode x = g.Head[top];

		int t = x.numEdges;
		int l = t;

		while (t != 0)
		{
			int adjacent = x.parent[l - t];

			if (visited[adjacent] == 0)
			{
				visited[adjacent] = -1;
				Enqueue(q, adjacent);
			}
			t--;
		}
	}
	if (n < 10)
	{
		hobby_recommend(g, begin, arr);
	}
}

void recommendations(Graph g, int id) //function that returns the recommended friends
{
	int friends[10];
	if (g.Head[id].numEdges == 0)
	{
		hobby_recommend(g, id, friends, 0);
	}
	else
		bfs(g, id, friends);
	printf("Your friend suggestions are :\n");
	fo(i, 10)
	{
		printf("%d) %s\nId: %d\n", i + 1, g.Head[friends[i]].name, friends[i]);
	}
}
void display_details(Graph g, int userID)
{
	printf("Name is %s", g.Head[userID].name);
	printf("City of location of user: %s", g.Head[userID].city);
}
void update_details()
{
}
void friendship_status()
{
}
void initialise() //all initalisation goes here
{
	push(&next_id, 0);
	init_hobby();
}
void delete_user(Graph g, int id)
{
	DeleteVertex(g, id);
	push(&next_id, id);
}
// void user_login(Graph g)
// {
//     int user_id,user_choice;
//     scanf("%d",&user_id);
//     printf("\n\t Please Enter User ID\n");
//     //if the user id doesn't exist, It displays error message and terminates function
//     if(g.Head[user_id].userExistence==0)
//     {
//         printf("\n\t***  The USER ID entered is INVALID. You Don't Exist in our World :((  ***\n");
//         return;
//     }
//     if(strcmp(g.Head[user_id].password,encrypt_pass(&g.Head[user_id])==0)
//     {
//         printf("\n\t1)\tAdd Friends (YAY ;P)\n\t2)\tRemove Friend (ono)\n\t3)\tCheck Friendlist :p\n");
//         printf("\t4)\tLook-up User ID :o\n\t5)\tLOG OUT :// \n\t6)\tDelete Account  :???\n");
//         do
//         {
//             switch(user_choice)
//             {
//                 case 1:
//                 {
//                     int new_frnd;   //  Take user_id of friend-to-be
//                     scanf("%d",&new_frnd);
//                     if(g.Head[new_frnd].userExistence==0)
//                     {
//                         printf("\n\t***  The User ID doesn't exist. Imaginary Friends FTW !  ***\n");
//                     }
//                     else
//                     {
//                         StartFollowing(g,user_id,new_frnd);//Adds friend
//                         printf("\n\tYAY You have a NEW Friend XD\n");
//                     }
//                     break;
//                 }
//                 case 2:
//                 {
//                     int no_more_frnd;
//                     scanf("%d",&no_more_frnd);
//                     if(g.Head[no_more_frnd].userExistence==0)
//                     {
//                         printf("\n\t***  The USER ID doesn't exist. Fighting with your Imagiinary Friends again?  ***\n");
//                     }
//                     else
//                     {
//                         Unfriend(g,user_id,no_more_frnd);   //  Removes Friend
//                         printf("\n\tUnfriended Successfully !!\n");
//                     }
//                     break;
//                 }
//                 case 3:
//                 {
//                     checkFriendlist(g,user_id);
//                     break;
//                 }
//                 case 4:
//                 {
//                     int look_user;   //  Take user_id of user to look up
//                     scanf("%d",&look_user);
//                     if(g.Head[look_user]userExistence==0)
//                     {
//                         printf("\n\t***  The User ID doesn't exist. File a Missing Persons Report !?  ***\n");
//                     }
//                     else
//                     {
//                         LookUpUser(g,user_id,look_user); //  Displays details
//                     }
//                     break;
//                 }
//                 case 5:
//                 {
//                     // logs-out user and terminates function
//                     printf("\n\t***  LOG-OUT SUCCESSFUL ! See You On The Other Side  ***\n");
//                     return;
//                     break;
//                 }
//                 case 6:
//                 {
//                     // deletes user
//                     Remove_user(g,user_id);
//                     return;
//                     break;
//                 }
//                 default:
//                 {
//                     printf("\n Blurry Vision? Time to visit an Optometrist? Or some Coffee?\n\n");
//                     break;
//                 }
//             }
//         }while(user_choice!=5 || user_choice!=6);
//     }
//     //if the password is incorrect, access is denied and function is terminated
//     else
//     {
//         printf("\n\t*** The Password is INCORRECT !! You looking for Trouble? Or Almonds? ***");
//         return;
//     }
//     return;
// }
// int main()
// {
// 	Graph alpha;
// 	alpha = CreateGraph(10);
// }
