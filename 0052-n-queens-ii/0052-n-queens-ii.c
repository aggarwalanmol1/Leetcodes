#include <stdbool.h>

void solve(int row, int n,
           bool *col,
           bool *diag1,
           bool *diag2,
           int *count) {

    if (row == n) {
        (*count)++;
        return;
    }

    for (int c = 0; c < n; c++) {

        int d1 = row - c + n - 1;
        int d2 = row + c;

        if (col[c] || diag1[d1] || diag2[d2])
            continue;

        col[c] = true;
        diag1[d1] = true;
        diag2[d2] = true;

        solve(row + 1, n, col, diag1, diag2, count);

        col[c] = false;
        diag1[d1] = false;
        diag2[d2] = false;
    }
}

int totalNQueens(int n) {

    bool col[15] = {false};
    bool diag1[30] = {false};
    bool diag2[30] = {false};

    int count = 0;

    solve(0, n, col, diag1, diag2, &count);

    return count;
}