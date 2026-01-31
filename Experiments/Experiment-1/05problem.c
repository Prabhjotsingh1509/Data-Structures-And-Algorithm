// Find the product of two matrices using pointers?

#include <stdio.h>

int main()
{
    int a1[50][50], a2[50][50], c[50][50];
    int i, j, k;
    int r1, c1, r2, c2;

    int (*p1)[50] = a1;
    int (*p2)[50] = a2;
    int (*pc)[50] = c;

    printf("Enter the no of rows you want:");
    scanf("%d", &r1);
    printf("Enter the no of rows you want:");
    scanf("%d", &c1);
    printf("Enter the no of rows you want:");
    scanf("%d", &r2);
    printf("Enter the no of rows you want:");
    scanf("%d", &c2);
    if (c1 != r2)
    {
        printf("Multiplication is not possible");
        return 0;
    }
    printf("Enter the element of first matrix");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", (*(a1 + i) + j));
        }
    }
    printf("Enter the element of second matrix");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", (*(a2 + i) + j));
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            *(*(c + i) + j) = 0;
            for (k = 0; k < c1; k++)
            {
                *(*(c + i) + j) += *(*(a1 + i) + k) * (*(*(a2 + k) + j));
            }
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", *(*(c + i) + j));
        }
        printf("\n");
    }
}
