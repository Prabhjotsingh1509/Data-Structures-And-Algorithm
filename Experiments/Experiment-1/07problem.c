// Wap to find linear search using dynamic memory allocation?
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[30];
    int i, k, n, found = 0;
    printf("Enter the number of element you want to enter in the array:");
    scanf("%d", &n);

    int(*ptr) = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("memory not allocated ");
        return 0;
    }

    printf("Enter the elements of the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("Enter the element you want to search:");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        if (ptr[i] == k)
        {
            found = 1;
            printf("The number is at the %d index", i);
            break;
        }
    }
    free(ptr);
    if (found == 0)
    {
        printf("Element not found");
    }

    return 0;
}