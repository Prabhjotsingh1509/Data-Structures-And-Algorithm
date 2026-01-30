// Create an array 'a1' with 'n' elements.insert an element in ith position of 'a1' and also delete an element from jth position of 'a1'
#include <stdio.h>

int main()
{
    int a1[50], n;
    int i, j, k;
    int p;
    printf("Enter the number of element you want to enter(not more than 49):");
    scanf("%d", &n);

    printf("Enter the number of elements of an array:");
    for (k = 0; k < n; k++)
    {
        scanf("%d", &a1[k]);
    }
    printf("Enter the position(index) in which you want to enter:");
    scanf("%d", &i);
    printf("Enter the number you want to enter at that position:");
    scanf("%d", &p);
    for (k = n; k > (i - 1); k--)
    {
        a1[k] = a1[k - 1];
    }
    a1[i] = p;

    printf("Enter the position(index) in which you want to del:");
    scanf("%d", &j);
    for (k = j; k <= n; k++)
    {
        a1[k] = a1[k + 1];
    }
    printf("The array is :");
    for (k = 0; k < n; k++)
    {
        printf("%d\n", a1[k]);
    }
    return 0;
}