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
    printf("\n\t  BONJOUR! WELCOME TO THE FRIENDS RECCOMENDATION SYSTEM \n\n");
    do
    {
        printf("\t********************************************************\n\n");
        printf("\t\t      *********************\n\t\t\tEnter your choice\n\t\t      *********************\n");
        printf("\t\t1)\tRegister new user\n\t\t2)\tLogin to your Profile\n\t\t3)\tCheck Friendship Status\n\t\t4)\tExit Program\n\n");
        printf("\t********************************************************\n");
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
            printf("Enter 1st user_id\n");
            scanf("%d",&v1); // takes id of first user
            printf("Enter 2nd user_id\n");
            scanf("%d",&v2); // takes id of second user
            if(CheckFriendshipStatus(graph,v1,v2))
                printf("\t***  The users are friends! Feeling Left Out !?  ***\n");
            else
                printf("\t***  The users are not friends. Need more friends? Maybe we can help! ;)  ***\n");
            break;
        }
        case 4:
            break;
        default:
            printf("\n\t Time to visit a Optometrist? Or some Coffee?\n\n");
            break;
        }
    } while (user_choice != 4);
    printf("\n\t****  Au Revoir Mon Amie :)  ****\n");
}
