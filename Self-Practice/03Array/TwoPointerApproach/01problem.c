// Given an array containing only 0s, 1s and 2s, sort the array without using any sorting algorithm.
// Two pointer approach
#include <stdio.h>

int sort(int arr[], int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp = arr[mid];
            arr[mid++] = arr[low];
            arr[low++] = temp;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high--] = temp;
        }
    }
}
int main()
{
    int arr[100] = {0, 1, 2, 0, 1, 2};
    int n = 6;
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}