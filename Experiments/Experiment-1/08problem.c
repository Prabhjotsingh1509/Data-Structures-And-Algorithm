// Wap to find the element using binary search?

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int low = 0, mid, upper = 6, k;

    printf("Enter the element you want to search:");
    scanf("%d", &k);
    while (low <= upper)
    {
        int mid = low + (upper - low) / 2;
        if (arr[mid] == k)
        {
            printf("%d", arr[mid]);
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
    return 0;
}
