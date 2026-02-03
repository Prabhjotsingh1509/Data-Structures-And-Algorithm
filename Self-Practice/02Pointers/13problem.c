// Write a function that returns a pointer to the largest element of an array.

#include <stdio.h>

int arrlarge(int *arr[], int n)
{
    int *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return (int)max;
}

int main()
{
    int *arr[30], n;
    // Enter the number of element you want.
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = arrlarge(arr, n);
    printf("%d", max);
}