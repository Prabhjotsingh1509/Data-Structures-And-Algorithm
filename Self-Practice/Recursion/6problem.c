// Write a C program using recursion to reverse a given number.

#include <stdio.h>

int reverse(int n, int d)
{
    if (n == 0)
    {
        return d;
    }
    int r = n % 10;
    d = (d * 10) + r;
    return reverse(n / 10, d);
}
int main()
{
    int n, d = 0;
    printf("Enter the number:");
    scanf("%d", &n);

    printf("%d", reverse(n, d));
}