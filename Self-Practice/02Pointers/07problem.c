// Write a program to find the largest element in an array using pointers.

#include <stdio.h>

int main()
{
    int arr[30] = {10, 5, 68, 47, 14};
    int *ptr = arr;
    int i, max = *ptr;

    for (i = 1; i < 5; i++)
    {
        if (max < *(ptr + i))
        {
            max = *(ptr + i);
        }
    }
    printf("The maximum element is:%d", max);
}