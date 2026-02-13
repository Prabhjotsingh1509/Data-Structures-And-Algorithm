/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>
#include <stdlib.h>

int *spiralMatrix(int **matrix, int rows, int cols, int *returnSize)
{
    int k = 0;
    int srow = 0, erow = rows - 1, scol = 0, ecol = cols - 1;
    while (srow <= erow && scol <= ecol)
    {
        // top
        for (int j = scol; j <= ecol; j++)
        {
            returnSize[k++] = matrix[srow][j];
        }
        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            returnSize[k++] = matrix[i][ecol];
        }
        // bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
            {
                break;
            }
            returnSize[k++] = matrix[erow][j];
        }
        // left
        for (int i = erow - 1; i > srow; i--)
        {
            if (scol == ecol)
            {
                break;
            }
            returnSize[k++] = matrix[i][scol];
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    return returnSize;
}

int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int **arr = malloc(rows * sizeof(int *));
    int *result = malloc(100 * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    spiralMatrix(arr, rows, cols, result);
    for (int i = 0; i < rows * cols; i++)
    {
        printf("%d ", result[i]);
    }
}