// Write a C program to declare an integer variable and a pointer to it. Print the value and address using the pointer.
#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x;
    printf("The address of x is %p\n", ptr);
    printf("The value of x:%d\n", *ptr);
    printf("The address of ptr:%p\n", &ptr);
    return 0;
}
