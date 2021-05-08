#ifndef __GRAPHS
#define __GRAPHS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include "stack.c"
#include "graph.h"
#include "graph.c"
#define fo(i, n) for (int i = 0; i < n; i++)
#define fod(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef unsigned long long llu;
typedef struct array_hobby
{
    char hobby[25];
} array_hobby;
array_hobby list_hobbies[8]; //stores hobby names
struct user
{
    char name[30];
    char city[30];
    char password[21];
    //birthday details
    int date;
    int month;
    int year;
    //add user hobby
    char hobbies[10]; //boolean string
    int no_followers;
    int *follower;
    int no_following;
    int *following;
};
typedef struct user User;
#endif