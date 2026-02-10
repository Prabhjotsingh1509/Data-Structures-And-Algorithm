/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>
#include <string.h>

void pald(char str[])
{
    int i = 0;
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);
    len--;
    while (i <= len)
    {
        if (str[i] != str[len])
        {
            printf("No");
            return;
        }
        i++;
        len--;
    }
    printf("Yes");
}
void main()
{
    char str[30];

    fgets(str, 30, stdin);
    pald(str);
    return;
}