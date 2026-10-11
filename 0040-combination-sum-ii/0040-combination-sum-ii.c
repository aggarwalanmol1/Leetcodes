#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* candidates, int candidatesSize,
               int target, int start,
               int* path, int pathSize,
               int*** result,
               int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        (*result)[*returnSize] = (int *)malloc(pathSize * sizeof(int));
        memcpy((*result)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Skip duplicate numbers
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];

        // Move to next index (cannot reuse same element)
        backtrack(candidates,
                  candidatesSize,
                  target - candidates[i],
                  i + 1,
                  path,
                  pathSize + 1,
                  result,
                  returnSize,
                  returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize,
                      int target,
                      int* returnSize,
                      int** returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), compare);

    int capacity = 200;

    int **result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));

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