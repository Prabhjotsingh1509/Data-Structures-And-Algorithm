// Write a program to print an array in reverse order using pointers only.

#include <stdio.h>

int main()
{
    int arr[30] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int n = 5, i;

    ptr = arr + (n - 1);

    for (i = (n - 1); i >= 0; i--)
    {
        printf("%d\t", *ptr);
        ptr--;
    }
}