
#include "struct.h"
#include <math.h>
array_hobby list_hobbies[8]; //stores hobby names
stack *next_id;
hobby *hobby_graph;
hobby *make_graph(int v) //simple graph
{
	hobby *temp;
	temp = (hobby *)malloc(sizeof(hobby));
	temp->v = v;
	temp->array = (ad_list *)malloc(v * sizeof(ad_list));
	fo(i, v) temp->array[i].head = NULL;
	return temp;
}
void make_edge(hobby *alpha, int e1, int e2) //simple graph , make edge
{
	ad_node *temp = (ad_node *)malloc(sizeof(ad_node));
	temp->vertex = e2;
	temp->next = alpha->array[e1].head;
	alpha->array[e1].head = temp;
}
/***************************************************************
 * choose_hobby take the string of hobbies from the user and stores the 
 * hobbies in a frerquncy array of hobbies.(Array that checks if the hobby is
 *                                                    choosen by the user)
 * Then a binary string is constructed from the frequency array.
 * e.g, if user chooses 2,5,7
 * a frequency array is constructed and the boolen string obtained is 01001010
 * Now in the graph(adjacecy list) containing verties (different boolen string permutations)
 * the edge is added. 
 * **************************************************************/
void choose_hobby(Graph g, int id)
{
	char choosen[25];
	scanf("%s", choosen);
	int count[8] = {};
	fo(i, strlen(choosen))
	{
		if (choosen[i] != ',')
		{
			count[choosen[i] - '1'] = 1;
		}
	}
	fo(i, 8) // copies
	{
		g.Head[id].hobbies[i] = count[i];
	}
	int number = 0;
	fo(i, 8)
	{
		number = number * 2 + count[7 - i];
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
	scanf("%s[^\n]", g.Head[id].name);
	printf("Enter your city : \n");
	scanf("%s[^\n]", g.Head[id].city);yOd6I/CBj/
yOd6I/CBj/
yOd6I/CBj/
yOd6I/CBj/
yOd6I/CBj/

	strcpy(g.Head[id].password,encrypt_pass(&g.Head[user_id]));
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
	choose_hobby(g, id);
	printf("Your Registration is complete and your assigned id is %d\n", id);
	g.Head[id].userExistence = 1;
	g.Head[id].vertexID = id;
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
/*******************************************************
 * hobby_recommend finds the users with most common hobbies in a efficient manner.
 * e.g, if the user string is 00100110
 * Part 1: (All hobbies of the user are covered)
 *   We replace all the 0's in the string with 1's 
 *   Here there are 5 0's so , 32 combinations of the string.
 *   We also store these permutations.
 * Part 2 : (Some hobbies are removed)
 *   We remove 1's from the main string and replace them with 0's.
 *   There are 3 1's and so 2^3 -1 combinations.
 * For each combinations, we again permute the 0's(from the stored array)
 * So , all the possible combinations are covered in a efficient manner.
 * ******************************************************/
int hobby_recommend(Graph g, int id, int arr[], int number)
{
	int temp[8];
	int n = 0;
	for (int i = 0; i < 8; i++)
	{
		if (g.Head[id].hobbies[i] != 1)
			n++;
	}
	perm store[(int)pow(2, n)];
	for (int zi = 0; zi < pow(2, n); zi++)
	{
		fo(i, 8) //copies the main string
		{
			temp[i] = g.Head[id].hobbies[i];
			store[zi].count[i] = 0;
		}
		int j = 0, m = zi, k = 0;
		while (m != 0) //converts iter to binary
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
			num = num * 2 + temp[7 - i];
		}

		ad_node *point = hobby_graph->array[num].head;
		while (point != NULL)
		{
			if (CheckFriendshipStatus(g, id, point->vertex))
			{
				if (point->vertex != id)
				{
					int flag = 1;
					fo(po, number)
					{
						if (arr[po] == point->vertex)
							flag = 0;
					}
					if (flag)
					{
						arr[number] = point->vertex;
						if (number == 10)
							break;
						number++;
					}
				}
			}
			point = point->next;
		}
	}
	int tn = 0; //=8 - n;

	for (int i = 0; i < 8; i++)
	{
		if (g.Head[id].hobbies[i] == 1)
			tn++;
	}

	if (number < 10)
	{
		for (int zi = pow(2, tn) - 2; zi >= 0; zi--)
		{
			for (int ko = pow(2, n) - 1; ko >= 0; ko--)
			{
				fo(i, 8)
					temp[i] = g.Head[id].hobbies[i]; //copies the main boolen string
				int j = 0, m = zi, k = 0;
				int count[8];
				fo(li, 8)
					count[li] = 0;
				while (m != 0) //converts iter to binary
				{
					count[k] = m % 2;
					m = m / 2;
					k++;
				}
				k = 0;
				int x = 0;
				fo(i, 8) //finds the permuted binary string
				{
					if (temp[i] == 1)
					{
						temp[i] = count[k];
						k++;
					}
					else
					{
						temp[i] = store[ko].count[x];
						x++;
					}
				}
				int num = 0;
				fo(i, 8) //finds the value in decimal after permutation
				{
					num = num * 2 + temp[7 - i];
				}
				ad_node *point = hobby_graph->array[num].head;
				while (point != NULL)
				{
					if (CheckFriendshipStatus(g, id, point->vertex))
					{
						int flag = 1;
						fo(po, number)
						{
							if (arr[po] == point->vertex)
								flag = 0;
						}
						if (flag)
						{
							arr[number] = point->vertex;
							if (number == 10)
								break;
							number++;
						}
					}
					point = point->next;
				}
			}
		}
	}
	return number;
}
int bfs(Graph g, int begin, int arr[])
{
	int n = 0; // If the no.of friends we get through bfs is less than 10
			   // then we use n -> no.of friends obtained by bfs
			   // We do bfs only till n<=10

	int x = g.numVertices;

	int visited[x]; // An array to keep track of the visited vertices

	int adjvisited[x]; // An array to tell whether a person is a direct friend of begin or not
					   // Begin and the adjacent vertices of begin are marked 1
					   // So that they won't get stored in the array, and the frinens of a
					   //person are not recommended again.
					   // If adjvisited[i] = 0 then i is not a direct friend of begin and i != x
					   // If adjvisited[j] = 0 then j is either a direct friend of begin or j == x
	for (int i = 0; i < x; i++)
	{					// In visited[x] array
		visited[i] = 0; // 0 indictes that the vertex is not visited
	}					// -1 indicates that the vertex is in the queue
						// 1 indicates that the vertex is visited

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
	} // Begin and the adjacent vertices of begin are marked 1

	adjvisited[begin] = 1;

	while (IsEmpty(q) != 1 && n <= 10)
	{
		int top = Dequeue(q);

		visited[top] = 1;

		if (adjvisited[top] != 1) // The top of Dequeue is stored in arr if
		{						  // he is not a direct friend of begin
			arr[n] = top;
			n++; // Increment n;
		}

		GraphNode x = g.Head[top];

		int t = x.numEdges;
		int l = t;

		while (t != 0) // for all the adjacent vertices of top we repeat the process
		{
			int adjacent = x.parent[l - t];

			if (visited[adjacent] == 0) // if that vertex is not visited
			{
				visited[adjacent] = -1; // -1 indicates that the number is in the queue
				Enqueue(q, adjacent);	// Enqueue that vertex
			}
			t--;
		}
	}
	if (n < 10) // If n is less than 10 then we call the hobby_recommend function
	{
		hobby_recommend(g, begin, arr, n);
	}
	return n;
}

void recommendations(Graph g, int id) //function that returns the recommended friends
{
	int friends[10], n;
	if (g.Head[id].numEdges == 0)
	{
		n = hobby_recommend(g, id, friends, 0);
	}
	else
	{
		n = bfs(g, id, friends);
		if (n < 10)
			n = hobby_recommend(g, id, friends, n);
	}
	printf("Your friend suggestions are :\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d) %s\nId: %d\n", i + 1, g.Head[friends[i]].name, friends[i]);
	}
}
void display_details(Graph g, int userID)
{
	printf("Name is %s\n", g.Head[userID].name);
	printf("City of location of user: %s\n", g.Head[userID].city);
	int flag = 0;
	printf("Hobbies : ");
	for (int i = 0; i < 8; i++)
		if (g.Head[userID].hobbies[i])
		{
			printf("%s ", list_hobbies[i].hobby);
			flag = 1;
		}

	if (!flag)
		printf("None\n");
	else
		printf("\n");
}
void common_hobbies(Graph g, int v1, int v2) //takes the boolean strings and \
                                            then uses AND operator to find the common hobbies
{

	int flag = 0;
	printf("Common Hobbies : ");
	for (int i = 0; i < 8; i++)
	{
		if (g.Head[v1].hobbies[i] && g.Head[v2].hobbies[i])
		{
			printf("%s ", list_hobbies[i].hobby);
			flag = 1;
		}
	}

	if (!flag)
		printf("Unfortunately none in common.");
}
void friendship_status(Graph g, int v1, int v2)
{
	int k = 0;
	k = CheckFriendshipStatus(g, v1, v2);
	if (k)
	{
		common_hobbies(g, v1, v2);
	}
}
void initialise() //all initalisation goes here
{
	push(&next_id, 0);
	init_hobby();
	hobby_graph = make_graph(512); //graph stores all the hobbies,there are 512 possibilities
}
void delete_user(Graph g, int id)
{
	DeleteVertex(g, id);
	push(&next_id, id);
}
void user_login(Graph g)
{
	int user_id, user_choice;
	printf("\n\tPlease Enter User ID\n");
	scanf("%d", &user_id);
	//if the user id doesn't exist, It displays error message and terminates function
	if (g.Head[user_id].userExistence == 0)
	{
		printf("\n\t***  The USER ID entered is INVALID. You Don't Exist in our World :((  ***\n");
		return;
	}
	if (strcmp(g.Head[user_id].password, encrypt_pass(&g.Head[user_id])) == 0)
	{

		do
		{
			printf("\n\t** What do you wanna do today? **\n\t1)\tAdd Friends (YAY ;P)\n\t2)\tRemove Friend (ono)\n\t3)\tCheck Friendlist :p\n");
			printf("\t4)\tLook-up User ID :o\n\t5)\tCheck Recommendations ;)\n\t6)\tLOG OUT :// \n\t7)\tDelete Account  :???\n");
			scanf("%d", &user_choice);
			switch (user_choice)
			{
			case 1:
			{
				int new_frnd; //  Take user_id of friend-to-be
				scanf("%d", &new_frnd);
				if (g.Head[new_frnd].userExistence == 0)
				{
					printf("\n\t***  The User ID doesn't exist. Imaginary Friends FTW !  ***\n");
				}
				else
				{
					if (CheckFriendshipStatus(g, user_id, new_frnd))
					{
						printf("sorry! we don't support multiple personality disorder :(");
					}
					StartFollowing(g, user_id, new_frnd); //Adds friend
					printf("\n\tYAY You have a NEW Friend XD\n");
				}
				break;
			}
			case 2:
			{
				int no_more_frnd;
				scanf("%d", &no_more_frnd);

				if (no_more_frnd == user_id)
				{
					printf("We can't help you resolve issues with yourself");
					break;
				}
				if (g.Head[no_more_frnd].userExistence == 0)
				{
					printf("\n\t***  The USER ID doesn't exist. Fighting with your Imagiinary Friends again?  ***\n");
					break;
				}
				else
				{
					//Unfriend(g,user_id,no_more_frnd);   //  Removes Friend

					if (!CheckFriendshipStatus(g, user_id, no_more_frnd))
					{
						printf("You gotta have friends to actually unfriend");
					}
					RemoveEdge(g, user_id, no_more_frnd);
					printf("\n\tUnfriended Successfully !!\n");
				}
				break;
			}
			case 3:
			{
				// checkFriendlist(g,user_id);

				PrintFriendList(g, user_id);
				break;
			}
			case 4:
			{
				int look_user; //  Take user_id of user to look up
				scanf("%d", &look_user);
				if (g.Head[look_user].userExistence == 0)
				{
					printf("\n\t***  The User ID doesn't exist. File a Missing Persons Report !?  ***\n");
				}
				else
				{
					LookUpUser(g, user_id, look_user); //  Displays details
				}
				break;
			}
			case 5:
			{
				//displays recommendations
				recommendations(g, user_id);
				break;
			}
			case 6:
			{
				// logs-out user and terminates function
				printf("\n\t***  LOG-OUT SUCCESSFUL ! See You On The Other Side  ***\n");
				return;
				break;
			}
			case 7:
			{
				// deletes user
				delete_user(g, user_id);
				return;
				break;
			}
			default:
			{
				printf("\n Blurry Vision? Time to visit an Optometrist? Or some Coffee?\n\n");
				break;
			}
			}
		} while (user_choice != 7 || user_choice != 6);
	}
	//if the password is incorrect, access is denied and function is terminated
	else
	{
		printf("\n\t*** The Password is INCORRECT !! You looking for Trouble? Or Almonds? ***\n");
		return;
	}
	return;
}
/*
int main()
{
	Graph alpha;
	alpha = CreateGraph(10);
}*/
// int main()
// {
// 	initialise();
// 	hobby_array();
// 	Graph alpha = CreateGraph(8);
// 	create_user(alpha);
// 	create_user(alpha);
// 	create_user(alpha);
// 	create_user(alpha);
// 	create_user(alpha);
// 	create_user(alpha);
// 	recommendations(alpha, 0);
// }
