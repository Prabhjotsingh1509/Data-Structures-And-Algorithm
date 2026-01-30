// convert uppercase string to lowercase using for loop

#include <stdio.h>

int main()
{
    char str[50];

    printf("Enter the string:");
    fgets(str, 50, stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            printf("%c", str[i] + 32);
        }
        else
        {
            printf("%c", str[i]);
        }
    }
}