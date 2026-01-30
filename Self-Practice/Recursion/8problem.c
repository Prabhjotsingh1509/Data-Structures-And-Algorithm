// Write a C program using recursion to print the Fibonacci series up to N terms.

#include <stdio.h>

int fibonacci(int a, int b, int n, int i)
{
    if (i > n)
    {
        return 0;
    }
    int c = a + b;
    printf("%d\t", c);
    i++;
    return fibonacci(a = b, c, n, i);
}
int main()
{
    int a = 0, b = 1, n, i = 0;
    printf("Enter the number:");
    scanf("%d", &n);
    printf("%d\t", a);
    printf("%d\t", b);
    fibonacci(a, b, n - 3, i);
    return 0;
}