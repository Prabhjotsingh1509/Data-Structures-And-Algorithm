/*Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:
Input:
6

Output:
8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6*/
#include <stdio.h>

int fibo(int n, int a, int b)
{
    if (n == 0)
    {
        return a;
    }
    return fibo(n - 1, b, a + b);
}
int main()
{
    int n;
    // number of terms you want to enter in this fibonacci series.
    scanf("%d", &n);
    printf("%d", fibo(n, 0, 1));
}