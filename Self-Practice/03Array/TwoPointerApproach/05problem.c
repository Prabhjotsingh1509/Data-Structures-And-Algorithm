// Given an integer array, find all unique triplets whose sum is equal to zero.
// {-1,0,1,2,1,-4}
#include <stdio.h>
#include <stdlib.h>
int compare_integers(const void *a, const void *b)
{
    // Cast the void pointers to integer pointers and dereference them
    int int_a = *((const int *)a);
    int int_b = *((const int *)b);

    // Return a value based on the comparison rules
    if (int_a < int_b)
        return -1;
    if (int_a > int_b)
        return 1;
    return 0;
}
int main()
{

    int i, j, k;
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Brute force
    // for (i = 0; i < n - 2; i++)
    // {
    //     for (j = i + 1; j < n - 1; j++)
    //     {
    //         for (k = j + 1; k < n; k++)
    //         {
    //             if (arr[i] + arr[j] + arr[k] == 0)
    //             {
    //                 printf("%d %d %d\n", arr[i], arr[j], arr[k]);
    //             }
    //         }
    //     }
    // }
    qsort(arr, n, sizeof(int), compare_integers);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // Two Pointer Approach
    for (i = 0; i < n; i++)
    {
        if (arr[i] == arr[i - 1] && i > 0)
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                printf("{%d,%d,%d}\n", arr[i], arr[j], arr[k]);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
            }
        }
    }
    free(arr);
    return 0;
}