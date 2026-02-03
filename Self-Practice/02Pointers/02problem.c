// Write a program to change the value of a variable using a pointer.

#include <stdio.h>

int main()
{
    int x = 10;
    // old value
    printf("The old value is :%d\n", x);
    int *ptr = &x;
    // we can access the x therough pointers.
    *ptr = 20;
    // new value
    printf("The new value is :%d", x);
    return 0;
}