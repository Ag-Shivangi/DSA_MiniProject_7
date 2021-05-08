#include "struct.h"
void user_login(Graph g)
{
    int user_id,user_choice;
    scanf("%d",&user_id);
    printf("\n\t Please Enter User ID\n")
    //if the user id doesn't exist, It displays error message and terminates function
    if(g.Head[user_id].userExistence==0)
    {
        printf("\n\t***  The USER ID entered is INVALID. You Don't Exist in our World :((  ***\n");
        return;
    }
    if(strcmp(g.Head[user_id].password),encrypt_pass(&g.Head[user_id])==0)
    {
        printf("\n\t1)\tAdd Friends (YAY ;P)\n\t2)\tRemove Friend (ono)\n\t3)\tCheck Friendlist :p\n");
        printf("\t4)\tLook-up User ID :o\n\t5)\tLOG OUT :// \n\t6)\tDelete Account  :???\n");
        do
        {
            switch(user_choice)
            {
                case 1:
                {
                    int new_frnd;   //  Take user_id of friend-to-be
                    scanf("%d",&new_frnd);
                    if(g.Head[new_frnd].userExistence==0)
                    {
                        printf("\n\t***  The User ID doesn't exist. Imaginary Friends FTW !  ***\n");
                    }
                    else
                    {
                        StartFollowing(g,user_id,new_frnd);//Adds friend
                        printf("\n\tYAY You have a NEW Friend XD\n");
                    }
                    break;
                }
                case 2:
                {
                    int no_more_frnd;
                    scanf("%d",&no_more_frnd);
                    if(g.Head[no_more_frnd].userExistence==0)
                    {
                        printf("\n\t***  The USER ID doesn't exist. Fighting with your Imagiinary Friends again?  ***\n");
                    }
                    else
                    {
                        Unfriend(g,user_id,no_more_frnd);   //  Removes Friend
                        printf("\n\tUnfriended Successfully !!\n");
                    }
                    break;
                }
                case 3:
                {
                    checkFriendlist(g,user_id);
                    break;
                }
                case 4:
                {
                    int look_user;   //  Take user_id of user to look up
                    scanf("%d",&look_user);
                    if(g.Head[look_user]userExistence==0)
                    {
                        printf("\n\t***  The User ID doesn't exist. File a Missing Persons Report !?  ***\n");
                    }
                    else
                    {
                        LookUpUser(g,user_id,look_user); //  Displays details
                    }
                    break;
                }
                case 5:
                {
                    // logs-out user and terminates function
                    printf("\n\t***  LOG-OUT SUCCESSFUL ! See You On The Other Side  ***\n");
                    return;
                    break;
                }
                case 6:
                {
                    // deletes user 
                    Remove_user(g,user_id);
                    return;
                    break;
                }
                default:
                {
                    printf("\n Blurry Vision? Time to visit an Optometrist? Or some Coffee?\n\n");
                    break;
                }
            }
        }while(user_choice!=5 || user_choice!=6);
    }
    //if the password is incorrect, access is denied and function is terminated
    else 
    {
        printf("\n\t*** The Password is INCORRECT !! You looking for Trouble? Or Almonds? ***");
        return;
    }
    return;
}