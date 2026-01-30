// Find the product of two matrices using pointers?

#include <stdio.h>

int main()
{
    int a1[50][50], a2[50][50], c[50][50];
    int i, j, k;
    int r1, c1, r2, c2;

    int *p1 = &a1[0][0];
    int *p2 = &a2[0][0];
    int *pc = &c[0][0];
    printf("Enter the no of rows you want:");
    scanf("%d", &r1);
    printf("Enter the no of rows you want:");
    scanf("%d", &c1);

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", (p1 + i * 50 + j));
        }
    }
    printf("Enter the no of rows you want:");
    scanf("%d", &r2);
    printf("Enter the no of rows you want:");
    scanf("%d", &c2);
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", (p2 + i * 50 + j));
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            *(pc + i * 50 + j) = 0;
            for (k = 0; k < c1; k++)
            {
                *(pc + i * 50 + j) += (*(p1 + i * 50 + k)) * (*(p2 + k * 50 + j));
            }
        }
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d ", *(pc + i * 50 + j));
        }
        printf("\n");
    }
}
