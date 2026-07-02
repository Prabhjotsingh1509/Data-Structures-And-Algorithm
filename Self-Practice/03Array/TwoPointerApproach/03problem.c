// Given an array, move all zeros to the end while maintaining the relative order of non-zero elements.
#include <stdio.h>
#include <stdlib.h>

void moveAllZeroes(int *arr, int n)
{
    int i, j = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    moveAllZeroes(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}