#include <stdio.h>
void display(int arr[], int n,int capacity)
{
    // Code for Traversal
    if (n >= capacity)
    {
        printf("Capacity exceed,Insertion failed!!!!\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // Code for Insertion
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 2,capacity = 100;
    display(arr, size,capacity);
    indInsertion(arr, size, element, capacity, index);
    if (size<=capacity)
    {
    size += 1;
    display(arr, size,capacity);
    }
    
    return 0;
}