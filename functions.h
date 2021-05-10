#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "graph.h"
typedef struct ad_node
{
    int vertex;
    struct ad_node *next;
    int weight;
} ad_node;
typedef struct ad_list
{
    struct ad_node *head;   
} ad_list;
typedef struct hobby
{
    int v;
    ad_list *array;
} hobby;
typedef struct perm
{
   int count[8];
}perm;
Graph CreateGraph(int size); //Creates the intial graph

void StartFollowing(Graph g, int v1, int v2); 

void resize_grpah(Graph* g);

void choose_hobby(Graph g, int id);

void create_user(Graph g);

void init_hobby();

int hobby_recommend(Graph g, int id, int arr[], int n);

int bfs(Graph g, int begin, int* arr);

void recommendations(Graph g, int id);

void display_details();

void update_details();

void friendship_status();

void initialise();

char *encrypt_pass(GraphNode *user_node);

void user_login(Graph g);

void common_hobbies(Graph g, int v1, int v2);
#endif
