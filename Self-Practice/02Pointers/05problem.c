// Write a program to access array elements using pointers instead of array indexing.

#include <stdio.h>

int main()
{
    int arr[30] = {10, 20, 40, 50};
    int *ptr = arr;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", *(ptr + i));
    }

    return 0;
}