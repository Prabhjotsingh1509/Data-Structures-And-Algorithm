/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include <stdio.h>

int main()
{
    int i, n, arr[100];
    int k, c = 0;
    // Enter the number of element yu want to enter in an array.
    scanf("%d", &n);
    // Elements of an array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // integer k (key to search)
    scanf("%d", &k);
    // linear searching
    for (i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            printf("Found at index %d\n", i);
            c++;
            printf("Comparisons=%d", c);
            return 0;
        }
        c++;
    }
    if (c == n)
    {
        printf("not found");
    }
    return 0;
}