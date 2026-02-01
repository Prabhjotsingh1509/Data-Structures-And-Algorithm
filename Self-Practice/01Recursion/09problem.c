// Write a C program using recursion to find the Nth Fibonacci number.
#include <stdio.h>

int fibonacci(int a, int b, int n, int i)
{
    int c = a + b;
    if (i >= n)
    {
        printf("%d", c);
        return 0;
    }
    i++;
    return fibonacci(a = b, c, n, i);
}
int main()
{
    int a = 0, b = 1, n, i = 0;
    printf("Enter the number:");
    scanf("%d", &n);
    fibonacci(a, b, n - 3, i);
    return 0;
}