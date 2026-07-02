#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[10];
    int k = 0;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[k++];
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = ((low + high) / 2);

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[5] = {7, 1, 14, 4, 8};

    mergesort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}