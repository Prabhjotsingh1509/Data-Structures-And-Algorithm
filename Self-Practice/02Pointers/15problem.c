// Write a program to swap two arrays using pointers.
#include <stdio.h>
int swap(int *arr1, int *arr2, int n)
{
    int temp;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}
int main()
{
    int arr1[100];
    int arr2[100];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    swap(arr1, arr2, n);
    printf("After Swapping:\n");
    printf("Array 1:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\nArray 2:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr2[i]);
    }
    return 0;
}