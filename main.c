#include "struct.h"
#include "functions.h"
int main()
{
    initialise(); //all initalisation goes here    
    int n = 256, user_choice, user_count = 0;
    int uid; //n=size of the user array(preferably a power of 2)
    Graph graph = CreateGraph(n);
    printf("\n  BONJOUR! WELCOME TO THE FRIENDS RECCOMENDATION SYSTEM \n\n");
    do
    {
        printf("********************************************************\n\n");
        printf("\t      *********************\n\t\tEnter your choice\n\t      *********************\n");
        printf("\t1)\tRegister new user\n\t2)\tLogin to your Profile\n\t3)\tExit Program\n\n");
        printf("********************************************************\n");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            user_count++;
            create_user(graph);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            scanf("%d", &uid);
            display_details(uid);
        default:
            printf("\n Time to visit a Optometrist? Or some Coffee?\n\n");
            break;
        }
    } while (user_choice != 3);
    printf("\n\t****  Au Revoir Mon Amie :)  ****\n");
}