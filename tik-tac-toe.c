#include <stdio.h>
#include <stdbool.h>

int isWin(int a[][4], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1)
            {
                return a[i][1];
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (a[1][j] == a[2][j] && a[2][j] == a[3][j] && a[1][j] != -1)
            {
                return a[1][j];
            }
        }
        if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != -1)
        {
            return a[1][1];
        }
        if (a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] != -1)
        {
            return a[1][3];
        }
    }
    return -1;
}
void printCell(int a[][4], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == -1)
                printf(" ");
            if (a[i][j] == 1)
                printf("X");
            if (a[i][j] == 2)
                printf("O");
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
    int n = 3, r, c;
    int a[4][4];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -1;
        }
    }

    bool player1 = true;
    bool player2 = false;
    while (true)
    {
        printCell(a, n);
        // check who winds
        if (isWin(a, n) == 1)
        {
            printf("Player1 won!\n");
            break;
        }
        else if (isWin(a, n) == 2)
        {
            printf("Player2 won!\n");
            break;
        }
        if (player1 == true)
        {
        // kaj
        // man=1
        Flag:
            printf("Player1 turn (X), Enter Row & Column: ");
            scanf("%d%d", &r, &c);
            if (a[r][c] != -1)
            {
                printf("Invalid cell\n");
                goto Flag;
            }
            a[r][c] = 1;
            player1 = false;
            player2 = true;
        }
        else
        {
        // kaj
        // man=2
        Flag2:
            printf("Player2 turn (O), Enter Row & Column: ");
            scanf("%d%d", &r, &c);
            if (a[r][c] != -1)
            {
                printf("Invalid cell\n");
                goto Flag2;
            }
            a[r][c] = 2;
            player2 = false;
            player1 = true;
        }
    }

    return 0;
}