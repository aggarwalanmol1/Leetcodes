#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void backtrack(int* nums, int numsSize,
               bool* used,
               int* path, int pathSize,
               int*** result,
               int* returnSize,
               int** returnColumnSizes) {

    if (pathSize == numsSize) {

        (*result)[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy((*result)[*returnSize], path, numsSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;

        return;
    }

    for (int i = 0; i < numsSize; i++) {

        if (used[i])
            continue;

        used[i] = true;
        path[pathSize] = nums[i];

        backtrack(nums,
                  numsSize,
                  used,
                  path,
                  pathSize + 1,
                  result,
                  returnSize,
                  returnColumnSizes);

        used[i] = false;   // Backtrack
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize,
              int** returnColumnSizes) {

    int capacity = 50000;

    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    bool used[10] = {false};
    int path[10];

    *returnSize = 0;

    backtrack(nums,
              numsSize,
              used,
              path,
              0,
              &result,
              returnSize,
              returnColumnSizes);

    return result;
}