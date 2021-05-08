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
    int no_followers;
    int *follower;
    int no_following;
    int *following;
};
typedef struct user User;
#endif