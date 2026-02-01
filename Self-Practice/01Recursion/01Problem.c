// Write a C program using recursion to print numbers from 1 to N.
#include <stdio.h>

int number(int n, int i)
{
    if (i > n)
    {
        return 0;
    }
    printf("%d\n", i);
    return number(n, i + 1);
}
int main()
{
    int n;
    int i = 1;
    printf("Enter the number:");
    scanf("%d", &n);

    number(n, i);
}
