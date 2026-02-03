// Write a program to compare two strings using pointers (without using strcmp()).
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[30], str2[30];
    char *ptr1 = str1, *ptr2 = str2;

    printf("Enter first string:");
    scanf("%s", str1);
    printf("Enter second string:");
    scanf("%s", str2);

    if (strlen(str1) != strlen(str2))
    {
        printf("Not equal");
        return 0;
    }
    while (*ptr1 != '\0')
    {
        if (*ptr1 != *ptr2)
        {
            printf("Not Equal");
            return 0;
        }
        ptr1++;
        ptr2++;
    }
    printf("Equal");
    return 0;
}