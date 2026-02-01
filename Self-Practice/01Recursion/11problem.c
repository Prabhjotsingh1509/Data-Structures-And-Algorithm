// Write a C program using recursion to find the length of a string without using strlen().

#include <stdio.h>
#include <string.h>
int len(char str[], int i)
{
    if (str[i] == '\0')
    {
        return i;
    }
    return len(str, i + 1);
}
int main()
{
    char str[30];
    printf("Enter the string:");
    fgets(str, 30, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("%d", len(str, 0));
}