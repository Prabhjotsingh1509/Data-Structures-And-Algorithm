// Find Sum of all Array elements using recursion?
#include <stdio.h>

int sum(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return a[n - 1] + sum(a, n - 1);
}
void main()
{
    int i, a[30], n;
    printf("Number of elements you want to enter in the array:");
    scanf("%d", &n);

    printf("Enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int sumarray = sum(a, n);
    printf("Sum of array:%d", sumarray);
}