// Write a program to find the sum of all elements of an array using pointers.

#include <stdio.h>

int main()
{
    int arr[30] = {10, 20, 40, 50};
    int *ptr = arr;
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += *(ptr + i);
    }
    printf("The Sum of elements of an array is :%d", sum);

    return 0;
}