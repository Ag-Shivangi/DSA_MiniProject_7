#include "struct.h"
void init_hobby()//initialises the hobbies in the database
{
   strcpy(list_hobbies[0].hobby,"Painting");
   strcpy(list_hobbies[1].hobby,"Dance");
   strcpy(list_hobbies[2].hobby,"Music");
   strcpy(list_hobbies[3].hobby,"Cricket");
   strcpy(list_hobbies[4].hobby,"Football");
   strcpy(list_hobbies[5].hobby,"Gaming");
   strcpy(list_hobbies[6].hobby,"Anime");
   strcpy(list_hobbies[7].hobby,"Programming");   
}
void choose_hobby()
{
    char choosen[30];
    scanf("%s",choosen); 
    fo(i,9)
    {
        
    }
    fo(i,strlen(choosen))
    {
       if(choosen[i]>40)
       {
           
       }

    }

}
