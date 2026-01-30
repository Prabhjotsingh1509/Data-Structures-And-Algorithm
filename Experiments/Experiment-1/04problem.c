// Find the sum of rows and columns of matrix of given order (row x column)

#include <stdio.h>

int main()
{
    int matrix[50][50];
    int i, j;
    int rows, column;
    printf("Enter the no of rows you want:");
    scanf("%d", &rows);
    printf("Enter the no of rows you want:");
    scanf("%d", &column);

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < rows; i++)
    {
        int sum = 0;
        for (j = 0; j < column; j++)
        {
            sum += matrix[i][j];
        }
        printf("sum of %d row is :%d\n", i + 1, sum);
    }
    for (j = 0; j < column; j++)
    {
        int sum = 0;
        for (i = 0; i < rows; i++)
        {
            sum += matrix[i][j];
        }
        printf("sum of %d column is :%d", j + 1, sum);
    }
}