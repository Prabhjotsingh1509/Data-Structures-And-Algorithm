// Given a sorted array and a target value, find two elements whose sum is equal to the target.
#include <stdio.h>
#include <stdlib.h>

int targetSum(int *arr, int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] < target)
        {
            low++;
        }
        else if (arr[low] + arr[high] > target)
        {
            high--;
        }
        else
        {
            printf("The two element whose sum is equal to target: %d %d ", arr[low], arr[high]);
            return 0;
        }
    }
    printf("Not found");
    return 0;
}

int main()
{
    int n, target;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);

    targetSum(arr, n, target);
    free(arr);
    return 0;
}