// Write a C program using recursion to find the factorial of a given number.
#include <stdio.h>

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d", &n);

    int f = fact(n);
    printf("%d", f);
}