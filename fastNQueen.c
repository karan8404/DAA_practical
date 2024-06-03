#include <stdio.h>
#include <stdbool.h>
#define N 4

struct Board
{
     bool col[N];
     bool row[N];
     bool lDiag[2 * N - 1];
     bool rDiag[2 * N - 1];
};

struct Board copyBoard(struct Board board)
{
     struct Board newBoard;
     for (int i = 0; i < N; i++)
     {
          newBoard.col[i] = board.col[i];
          newBoard.row[i] = board.row[i];
     }
     for (int i = 0; i < 2 * N - 1; i++)
     {
          newBoard.lDiag[i] = board.lDiag[i];
          newBoard.rDiag[i] = board.rDiag[i];
     }
     return newBoard;
}

int indexToLdiag(int i, int j)
{
     return i + j;
}

int indexToRdiag(int i, int j)
{
     return i - j + N - 1;
}

bool isSafe(int i, int j, struct Board board)
{
     return (!board.col[j] && !board.row[i] && !board.lDiag[indexToLdiag(i, j)] && !board.rDiag[indexToRdiag(i, j)]);
}

void printBoard(struct Board board)
{
     for (int i = N - 1; i >= 0; i--)
     {
          for (int j = 0; j < N; j++)
          {
               if (board.col[j] && board.row[i])
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
}

void nQueen(int i, struct Board board)
{
     if (i >= N)
     {
          printf("Solution:\n");
          printBoard(board);
          return;
     }

     for (int j = 0; j < N; j++)
     {
          if (isSafe(i, j, board))
          {
               struct Board newBoard = copyBoard(board);
               newBoard.col[j] = true;
               newBoard.row[i] = true;
               newBoard.lDiag[indexToLdiag(i, j)] = true;
               newBoard.rDiag[indexToRdiag(i, j)] = true;

               nQueen(i + 1, newBoard);
          }
     }
}

int main()
{
     struct Board board;
     for (int i = 0; i < N; i++)
     {
          board.col[i] = false;
          board.row[i] = false;
     }
     for (int i = 0; i < 2 * N - 1; i++)
     {
          board.lDiag[i] = false;
          board.rDiag[i] = false;
     }
     printf("%d", isSafe(0, 0, board));
     
     printf("%d", isSafe(0, 1, board));
     // nQueen(0, board);
     return 0;
}