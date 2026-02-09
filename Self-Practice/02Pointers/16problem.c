// Write a program to create an array of pointers.

#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr[5]; // array of pointers
    int i;

    // store addresses of array elements in pointer array
    for (i = 0; i < 5; i++)
    {
        ptr[i] = &arr[i];
    }

    // print values using pointer array
    printf("Array elements using pointer array:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *ptr[i]);
    }

    return 0;
}
