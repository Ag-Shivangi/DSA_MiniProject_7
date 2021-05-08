#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include "struct.h"

Graph CreateGraph(int size); //Creates the intial graph

void StartFollowing(Graph g, int v1, int v2); 

void resize_grpah(Graph* g);

void choose_hobby(int a);

void create_user(Graph g);

void init_hobby();

void hobby_recommend(Graph g, int id);

int bfs(Graph g, int begin, int* arr);

void recommendations(Graph g, int id);

void display_details();

void update_details();

void friendship_status();

void initialise();

#endif