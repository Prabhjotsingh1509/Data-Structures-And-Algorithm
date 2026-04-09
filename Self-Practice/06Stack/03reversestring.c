/*Q3. Reverse a String Using Stack

Given a string, reverse it using a stack.

Input: "hello"
Output: "olleh"*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
char stack[SIZE];
int top = -1;
int main()
{
    char str[100];
    int i = 0;

    printf("Enter the string");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    while (str[i] != '\0')
    {
        top++;
        stack[top] = str[i];
        i++;
    }
    while (top >= 0)
    {
        printf("%c", stack[top]);
        top--;
    }
    return 0;
}
