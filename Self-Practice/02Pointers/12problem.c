// Write a program to pass an array to a function using pointers.

#include <stdio.h>
int arrpass(int *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int main()
{
    int n;
    int *arr[30];

    printf("Enter the element of an array:");
    scanf("%d", &n);
    arrpass(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}