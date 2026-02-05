// Wap to find the element using binary search?

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int low = 0, mid, upper = 6, k, found = -1;

    printf("Enter the element you want to search:");
    scanf("%d", &k);
    while (low <= upper)
    {
        int mid = low + (upper - low) / 2;
        if (arr[mid] == k)
        {
            found = 1;
            printf("%d", mid);
            break;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            upper = mid - 1;
        }
    }
    if (found == -1)
    {
        printf("not found");
    }
    return 0;
}
