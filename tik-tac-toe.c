#include <stdio.h>

void printCell(int a[][4], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == -1)
                printf(" ");
            if (j < n)
                printf("\t|\t");
        }
        printf("\n");
        if (i < n)
            printf("\n____________________________________");
        printf("\n\n");
    }
}
int main()
{
    int n = 3;
    int a[4][4];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -1;
        }
    }

    printCell(a, n);

    return 0;
}