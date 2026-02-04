// Write a program to calculate sum and average of array elements using pointers and functions.
#include <stdio.h>
int sumAndAverage(int *arr, int n, int *sum, float *avg)
{
    int i;
    *sum = 0;
    for (i = 0; i < n; i++)
    {
        *sum = *sum + *(arr + i);
    }
    *avg = (float)*sum / n;
}
int main()
{
    int i, n;
    int sum;
    float avg;
    int arr[100];
    // Enter the number of element you want to enter
    scanf("%d", &n);
    // Enter the elements of an array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Function call
    sumAndAverage(arr, n, &sum, &avg);
    printf("Sum=%d\n", sum);
    printf("Average=%f", avg);
    return 0;
}