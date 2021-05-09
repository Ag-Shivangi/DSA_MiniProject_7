#include "struct.h"
// Takes the pointer to a user node  and returns string
char * encrypt_pass(GraphNode* user_node)
{
    char salt[] = "$1$3456789";
    salt[3]=user_node->name[0];
    salt[4]=user_node->name[1];
    salt[5]=user_node->name[2];
    salt[6]=user_node->city[0];
    salt[7]=user_node->city[1];
    salt[9]=user_node->name[3];
    char *password;
    /*************************************************************************************************
    * The salt :
    *
    * The first three characters "$1$" signifies the algorithm (in this case the MD5 based)
    * The next 3 characters are the first 3 letters of their name
    * The next 2 characters are the first 2 letters of their city
    * The next character is the digit 8
    * The next character is the 4th letter of their name
    **************************************************************************************************/
    // Read in the user's password and encrypt it. 
    password = crypt(getpass("Password:"), salt);
    return(password);
}
