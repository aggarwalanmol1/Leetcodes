#include <stdlib.h>
#include <string.h>

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize,
               int*** result, int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
        memcpy((*result)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        // Reuse same element, so pass i
        backtrack(candidates,
                  candidatesSize,
                  target - candidates[i],
                  i,
                  path,
                  pathSize + 1,
                  result,
                  returnSize,
                  returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target,
                     int* returnSize,
                     int** returnColumnSizes) {

    int capacity = 200;

    int **result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    int path[100];

    *returnSize = 0;

    backtrack(candidates,
              candidatesSize,
              target,
              0,
              path,
              0,
              &result,
              returnSize,
              returnColumnSizes);

    return result;
}