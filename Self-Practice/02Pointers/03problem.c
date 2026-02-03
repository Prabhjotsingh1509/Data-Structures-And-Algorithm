// Write a program to swap two numbers using pointers.
#include <stdio.h>

int main()
{
    int x = 10, y = 20;
    int *ptr1 = &x, *ptr2 = &y;
    int temp;

    printf("The value of x:%d\n", x);
    printf("The value of y:%d\n", y);

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("The value of x:%d\n", x);
    printf("The value of y:%d\n", y);

    return 0;
}