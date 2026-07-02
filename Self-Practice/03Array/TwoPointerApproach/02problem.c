// Given a sorted array, remove duplicates in-place and return the new length.
/* Input:
    {1,1,2,3,3,4,4}
    Output:
    {1,2,3,4}
*/
#include <stdio.h>
#include <stdlib.h>
int *remDuplicate(int *arr, int n, int *returnSize)
{
    int k = 0;
    int *result = malloc(n * sizeof(int));
    result[k++] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            result[k++] = arr[i];
        }
    }
    *returnSize = k;
    return result;
}
int main()
{
    int n;
    int s = 0;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *result = remDuplicate(arr, n, &s);
    // printf("%d", s);
    for (int i = 0; i < s; i++)
    {
        printf("%d ", result[i]);
    }
    free(arr);
    return 0;
}
