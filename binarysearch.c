#include <stdio.h>
// finds the left index
int find_left_index(int arr[], int size_array, int element)
{
    int low = 0, high = size_array - 1, result = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (element == arr[mid])
        {
            result = mid;
            high = mid - 1;
        }
        else if (element < arr[mid]) 
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return result;
}
// finds the right index
int find_right_index(int arr[], int size_array, int element)
{
    int low = 0, high = size_array - 1, result = -1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (element == arr[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (element < arr[mid]) 
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return result;
}
