#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 20

char board[N][N];
int n;
int solutions = 0;
int totalSolutions = 0;

void printProgressBar(int percent)
{
    printf("\r[");
    for (int i = 0; i < 50; i++)
    {
        if (i < (percent / 2))
        {
            printf("#");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%", percent);
    fflush(stdout);
}

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

bool solveNQueens(int col, bool countOnly)
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
        if (!countOnly)
            printProgressBar(solutions * 100 / totalSolutions); // update progress bar
        return false;
    }
    int i;

    for (i = 0; i < n; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 'Q';

            solveNQueens(col + 1, countOnly);

            board[i][col] = '.';
        }
    }
    // printProgressBar((col + 1) * 100 / n); // update progress bar
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

    int i;
    int j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = '.';
        }
        // printProgressBar((i + 1) * 100 / N); // update progress bar
    }
    // printf("\n");

    // calculate the space taken by the board
    int space = sizeof(board);
    printf("Space taken by the board: %d bytes\n", space);

    clock_t start1 = clock(); // start the timer
    solveNQueens(0, true);
    clock_t end1 = clock();                                        // end the timer
    double time_taken1 = ((double)end1 - start1) / CLOCKS_PER_SEC; // calculate the time taken
    totalSolutions = solutions;
    solutions = 0; // reset solutions count

    clock_t start = clock(); // start the timer
    solveNQueens(0, false);  // second run to find solutions and update progress bar

    clock_t end = clock();                                      // end the timer
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC; // calculate the time taken

    if (solutions == 0)
        printf("\nNo solution found.\n");
    else
        printf("\nTotal solutions: %d\n", solutions);

    printf("Time taken to count solutions: %f seconds\n", time_taken1);
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}