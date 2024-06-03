#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 20

char board[N][N];
int n;
int solutions = 0;

bool isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

bool solveNQueens(int col)
{
    if (col >= n)
    {
        solutions++;
        // printf("Solution %d:\n", solutions);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         printf("%c ", board[i][j]);
        //     printf("\n");
        // }
        // printf("\n");
        return false;
    }
    int i;

    for (i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 'Q';

            solveNQueens(col + 1);

            board[i][col] = '.';
        }
    }

    return false;
}

int main()
{
    printf("Enter the number of queens (max %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N)
    {
        printf("Invalid input!\n");
        return 1;
    }
    clock_t start = clock(); // start the timer

    int i;
    int j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = '.';

    solveNQueens(0);

    clock_t end = clock();                                      // end the timer
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC; // calculate the time taken

    if (solutions == 0)
        printf("No solution found.\n");
    else
        printf("Total solutions: %d\n", solutions);

    
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}