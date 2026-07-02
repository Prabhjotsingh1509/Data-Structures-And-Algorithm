#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[50][50], arr2[50][50];
    int i, j, n, k;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    int product[50][50];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }
}
