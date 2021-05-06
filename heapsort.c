#include <stdio.h>
#include <stdlib.h>
//creating a max heap
void heapify(int n,int * arr, int i)
{
    // n = number of elements in the heap
    // arr = array with elements to be heapified
    int largest =i;
    int left_index = 2*largest + 1;
    int right_index = 2*(largest+1);
    int temp;
    if(left_index<n && arr[left_index]>arr[largest])
    {
        largest=left_index;
    }
    if(right_index<n && arr[right_index]>arr[largest])
    {
        largest=right_index;
    }
    if (largest!=i)
    {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(n,arr,largest);
    }
    return;
}
void create_max_heap(int n, int * a)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(n,a,i);
    }    
}
//sorts in increasing order: [1,2,3,4,5]
void heapsort(int n, int * arr)
{
    for (int i = n - 1; i >= 0; i--) 
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify( i,arr, 0);
    }
}
