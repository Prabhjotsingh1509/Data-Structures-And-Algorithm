// Write a program to find the length of a string using pointers (without using strlen()).

#include <stdio.h>

int main()
{
    char str[30] = "Prabhjot";
    char *ptr = str;
    int len = 0;
    while (*ptr != '\0')
    {
        len++;
        ptr++;
    }
    printf("The length of string is :%d", len);
}