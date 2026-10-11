#include <stdlib.h>
#include <string.h>

char *map[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int index, char *path,
               char **result, int *returnSize) {

    if (digits[index] == '\0') {
        path[index] = '\0';
        result[*returnSize] = (char *)malloc(strlen(path) + 1);
        strcpy(result[*returnSize], path);
        (*returnSize)++;
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        path[index] = letters[i];
        backtrack(digits, index + 1, path, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;

    if (digits[0] == '\0')
        return NULL;

    int max = 1000;   // Enough for constraints
    char **result = (char **)malloc(max * sizeof(char *));
    char path[5];     // Max digits = 4

    backtrack(digits, 0, path, result, returnSize);

    return result;
}