// Wap to linear search the element in the srray ?
#include <stdio.h>

int main()
{
    int a[30], n;
    int i, k;
    printf("Enter the number of element you want to enter in the array:");
    scanf("%d", &n);

    printf("Enter the elements of the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element you want to search:");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            printf("The number is at the %d index:", i);
            return 0;
        }
    }
    printf("Element not found");
    return 0;
}