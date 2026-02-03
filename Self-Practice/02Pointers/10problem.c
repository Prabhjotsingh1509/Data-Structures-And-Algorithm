// Write a program to copy one string to another using pointers.

#include <stdio.h>

int main()
{
    char str[30], str1[30];
    char *ptr1 = str, *ptr2 = str1;
    int l = 0;
    printf("Enter the string:");
    scanf("%s", str);

    while (*ptr1 != '\0')
    {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
        l++;
    }
    *ptr2 = '\0';
    // while (l > 0)
    // {
    //     l--;
    //     ptr2--;
    // }
    // printf("%d", l);
    ptr2 = str1;
    while (*ptr2 != '\0')
    {
        printf("%c", *ptr2);
        ptr2++;
    }
    *ptr2 = '\0';
    return 0;
}