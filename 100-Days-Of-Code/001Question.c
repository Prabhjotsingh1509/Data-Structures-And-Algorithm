/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int pos, num;
    printf("Enter the number of element you want to enter:");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    if (arr == NULL)
    {
        printf("memory not allocated");
        return 0;
    }
    printf("Enter the elements of an array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position at which you want to enter the element:");
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        free(arr);
        return 0;
    }
    printf("Enter the element you want to enter:");
    scanf("%d", &num);
    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    for (i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}