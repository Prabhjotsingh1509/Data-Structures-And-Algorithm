// Write a program to find the sum of two numbers using pointers.

#include <stdio.h>

int main()
{
    int x = 10, y = 20;
    int *ptr1 = &x, *ptr2 = &y;

    int sum = *ptr1 + *ptr2;

    printf("The sum of %d and %d : %d", *ptr1, *ptr2, sum);

    return 0;
}