/*Q6. Next Greater Element (Basic)

Given an array, find the next greater element for each element.

Input: [4, 5, 2, 25]
Output: [5, 25, 25, -1]*/
#include <stdio.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

int main()
{
    int n;
    int arr[100];
    int result[100];
    printf("Number of element you want to enter:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 && stack[top] <= arr[i])
        {
            top--;
        }
        if (top == -1)
        {
            result[i] = -1;
        }
        else
        {
            result[i] = stack[top];
        }
        top++;
        stack[top] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", result[i]);
    }
    return 0;
}
