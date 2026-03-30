/*Q09. Stock Span Problem

Given daily stock prices, find the span for each day.

Input: [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;
void push(int i)
{
    top++;
    stack[top] = i;
}
void pop()
{
    top--;
}
int main()
{
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int arr[n], result[n];
    printf("Enter the stock prices for each day: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        while (top != -1 && arr[i] > arr[stack[top]])
        {
            pop();
        }
        if (i == 0)
        {
            result[i] = 1;
        }
        else
        {
            int span = i - stack[top];
            result[i] = span;
        }
        push(i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", result[i]);
    }
}