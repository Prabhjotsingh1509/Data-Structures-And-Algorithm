// Write a C program using recursion to calculate xⁿ (power of a number) without using any loop or library function.
#include <stdio.h>
int power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}
int main()
{
    int n, x;
    printf("Enter the number:");
    scanf("%d", &x);
    printf("Enter the number:");
    scanf("%d", &n);

    printf("%d", power(x, n));
}