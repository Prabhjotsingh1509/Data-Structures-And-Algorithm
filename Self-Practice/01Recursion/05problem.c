// Write a C program using recursion to count the number of digits in a given number.
#include <stdio.h>

int countnum(int n, int count)
{
    if (n == 0)
    {
        return count;
    }
    count++;
    return countnum(n / 10, count);
}
int main()
{
    int n, count = 0;
    printf("Enter the number:");
    scanf("%d", &n);

    printf("%d", countnum(n, count));
}