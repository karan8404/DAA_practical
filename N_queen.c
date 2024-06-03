#include <stdio.h>
#include <time.h>

int N = 11;

void printSolution(int board[N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int checkRow(int board[N], int row, int pos)
{
    for (int i = 0; i < row; i++)
        if (board[i] == pos)
            return 0;
    return 1;
}

int checkDiagonals(int board[N], int row, int pos)
{
    int i;
    for (i = 1; i <= N - 1; i++) // left diagonal, top-left
    {
        if ((row - i) < 0 || (pos - i) < 0)
            break;
        if (board[row - i] == pos - i)
            return 0;
    }

    for (i = 1; i <= N - 1; i++) // right diagonal, bottom-left
    {
        if ((row - i) < 0 || (pos + i) > N - 1)
            break;
        if (board[row - i] == pos + i)
            return 0;
    }
    return 1;
}

void nQueen(int board[N], int row)
{
    if (row >= N)
    {
        // printSolution(board);
        return;
    }
    for (int i = 0; i < N; i++) // checking all positions vertically in the row
    {
        if (checkRow(board, row, i) && checkDiagonals(board, row, i))
        {
            board[row] = i;
            nQueen(board, row + 1);
        }
    }
}

int main()
{
    int board[N];

    clock_t start = clock(); // start the timer
    for (int i = 0; i < N; i++)
        board[i] = -1;

    nQueen(board, 0);

    clock_t end = clock();                                      // end the timer
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; // calculate elapsed time
    printf("Time taken: %f\n", time_spent);
}