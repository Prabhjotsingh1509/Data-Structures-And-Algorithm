/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/

#include <stdio.h>
#include <stdlib.h>

int identity(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && arr[i][j] != 1)
            {
                return 0;
            }
            else if (i != j && arr[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int **arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    if (identity(arr, n) == 0)
    {
        printf("not identity matrix");
    }
    else
    {
        printf("identity matrix");
    }
    free(arr);
    return 0;
}