/*Q11. Previous Smaller Element

Find the nearest smaller element to the left for each element.

Input: [4, 5, 2, 10, 8]
Output: [-1, 4, -1, 2, 2]*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int data)
{
    top++;
    stack[top] = data;
}
void pop()
{
    top--;
}
int main()
{
    int n, i;
    printf("Enter the element you want to enter in the array");
    scanf("%d", &n);
    int arr[n], result[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        while (arr[i] < stack[top])
        {
            pop();
        }
        if (top == -1)
        {
            result[i] = -1;
            ;
        }
        else
        {
            result[i] = stack[top];
        }
        push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", result[i]);
    }
}