#include "struct.h"
#include "functions.h"
#include "functions.c"
#include "graph.c"
#include "header.c"
#include "encrypt.c"
int main()
{
    initialise(); //all initalisation goes here    
    int n = 256, user_choice, user_count = 0; //n=size of the user array(preferably a power of 2)
    Graph graph = CreateGraph(n);
    printf("\n  BONJOUR! WELCOME TO THE FRIENDS RECCOMENDATION SYSTEM \n\n");
    do
    {
        printf("********************************************************\n\n");
        printf("\t      *********************\n\t\tEnter your choice\n\t      *********************\n");
        printf("\t1)\tRegister new user\n\t2)\tLogin to your Profile\n\t3)\tCheck Friendship Status\n\t4)\tExit Program\n\n");
        printf("********************************************************\n");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
        {
            user_count++;
            create_user(graph);
            break;
        }
        case 2: 
        {
            user_login(graph);
            break;
        }
        case 3:
        {
            int v1,v2;
            scanf("%d",&v1); // takes id of first user
            scanf("%d",&v2); // takes id of second user
            if(CheckFriendshipStatus(graph,v1,v2))
                printf("The user is your friend! Shouldn't you already be knowing that !?");
            else
                printf("Nope.");
            break;
        }
        case 4:
            break;
        default:
            printf("\n Time to visit a Optometrist? Or some Coffee?\n\n");
            break;
        }
    } while (user_choice != 4);
    printf("\n\t****  Au Revoir Mon Amie :)  ****\n");
}
