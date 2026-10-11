#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.')
                continue;

            int num = board[i][j] - '1';      // Convert '1'-'9' to 0-8
            int boxIndex = (i / 3) * 3 + (j / 3);

            // Duplicate found
            if (row[i][num] || col[j][num] || box[boxIndex][num])
                return false;

            row[i][num] = true;
            col[j][num] = true;
            box[boxIndex][num] = true;
        }
    }

    return true;
}