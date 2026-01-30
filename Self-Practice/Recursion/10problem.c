// Write a C program using recursion to check whether a given string is a palindrome.
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end)
{
    if (start >= end)
        return 1;

    if (str[start] != str[end])
        return 0;

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    char str[30];
    int len;

    printf("Enter the string: ");
    fgets(str, 30, stdin);
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    if (isPalindrome(str, 0, len - 1))
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}