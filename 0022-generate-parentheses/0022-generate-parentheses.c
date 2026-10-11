#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current,
               int open, int close, int n) {

    if (open == n && close == n) {
        current[2 * n] = '\0';
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[open + close] = '(';
        backtrack(result, returnSize, current, open + 1, close, n);
    }

    if (close < open) {
        current[open + close] = ')';
        backtrack(result, returnSize, current, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxSize = 15000;   // Enough for n <= 8
    char **result = (char **)malloc(maxSize * sizeof(char *));
    char current[20];

    *returnSize = 0;

    backtrack(result, returnSize, current, 0, 0, n);

    return result;
}