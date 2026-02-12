/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the matrix

Output:
- Print "Symmetric Matrix" if the given matrix is symmetric
- Otherwise, print "Not a Symmetric Matrix"

Example:
Input:
3 3
1 2 3
2 4 5
3 5 6

Output:
Symmetric Matrix

Explanation:
The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

Test Cases:

Test Case 1:
Input:
2 2
1 2
2 1
Output:
Symmetric Matrix

Test Case 2:
Input:
3 3
1 0 1
2 3 4
1 4 5
Output:
Not a Symmetric Matrix

Test Case 3:
Input:
2 3
1 2 3
4 5 6
Output:
Not a Symmetric Matrix*/

#include <stdio.h>
#include <stdlib.h>

int symmetric(int **arr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int i, j;
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    if(rows != cols)
    {
        printf("Number of rows and cols must be equal");
        return 0;
    }
    int **arr = malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory not allocated");
        return 0;
    }
    for (i = 0; i < rows; i++)
    {
        arr[i] = malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("malloc failed for row data");
            return 0;
        }
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    if (symmetric(arr, rows, cols) == 1)
    {
        printf("Symmetric Matrix");
    }
    else
    {
        printf("Not symmetric Matrix");
    }
    return 0;
}