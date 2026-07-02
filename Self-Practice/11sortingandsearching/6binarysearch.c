#include <stdio.h>

int binarysearch(int arr[], int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + ((high - low) / 2);

    if (arr[mid] == key)
    {
        return 1;
    }
    else if (arr[mid] > key)
    {
        return binarysearch(arr, key, low, mid - 1);
    }
    else
    {
        return binarysearch(arr, key, mid + 1, high);
    }
}

int main()
{
    int arr[5] = {1, 4, 7, 8, 9};

    int num = binarysearch(arr, 4, 0, 4);

    if (num == 1)
    {
        printf("found");
    }
    else
    {
        printf("not found");
    }
}