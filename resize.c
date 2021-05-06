#include "struct.h"
//  itemcount is the no. of elements in the array
//  size_array is the size of the array
User * resize_user_array(int itemcount, int* size_array, User * array_of_users)
{
    User * resized_arr;
    resized_arr=(User *)realloc(array_of_users,sizeof(User)*2*itemcount);
    *size_array= 2*itemcount;
    return resized_arr;
}
int * resize_int_array(int itemcount, int* size_array, int* array)
{
    int * resized_arr;
    resized_arr=(int *)realloc(array,sizeof(int)*2*itemcount);
    *size_array=2*itemcount;
    return resized_arr;
}