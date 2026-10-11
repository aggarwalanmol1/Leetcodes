#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSafe(char **board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row,
           int n,
           char **board,
           char ****result,
           int *returnSize,
           int *capacity) {

    if (row == n) {

        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char **));
        }

        (*result)[*returnSize] = malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            (*result)[*returnSize][i] = strdup(board[i]);
        }

        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            board[row][col] = 'Q';

            solve(row + 1,
                  n,
                  board,
                  result,
                  returnSize,
                  capacity);

            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n,
                     int* returnSize,
                     int** returnColumnSizes) {

    char **board = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = malloc(n + 1);

        for (int j = 0; j < n; j++)
            board[i][j] = '.';

        board[i][n] = '\0';
    }

    int capacity = 100;

    char ***result = malloc(capacity * sizeof(char **));

    *returnSize = 0;

    solve(0,
          n,
          board,
          &result,
          returnSize,
          &capacity);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = n;

    for (int i = 0; i < n; i++)
        free(board[i]);

    free(board);

    return result;
}