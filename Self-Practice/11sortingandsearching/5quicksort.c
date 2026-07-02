#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivtidx = partition(arr, low, high);

        quicksort(arr, low, pivtidx - 1);

        quicksort(arr, pivtidx + 1, high);
    }
}

int main()
{
    int arr[5] = {7, 1, 9, 8, 3};

    quicksort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}