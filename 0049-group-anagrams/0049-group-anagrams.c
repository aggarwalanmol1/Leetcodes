#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize,
                      int** returnColumnSizes) {

    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));

    char **keys = (char **)malloc(strsSize * sizeof(char *));
    int groups = 0;

    for (int i = 0; i < strsSize; i++) {

        char *key = strdup(strs[i]);
        qsort(key, strlen(key), sizeof(char), cmpChar);

        int index = -1;

        for (int j = 0; j < groups; j++) {
            if (strcmp(keys[j], key) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {

            keys[groups] = key;

            result[groups] = (char **)malloc(strsSize * sizeof(char *));
            result[groups][0] = strs[i];

            (*returnColumnSizes)[groups] = 1;

            groups++;
        }
        else {

            result[index][(*returnColumnSizes)[index]] = strs[i];
            (*returnColumnSizes)[index]++;

            free(key);
        }
    }

    *returnSize = groups;

    free(keys);

    return result;
}