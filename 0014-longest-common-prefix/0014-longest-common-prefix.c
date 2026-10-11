#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";

    int i, j;
    int len = strlen(strs[0]);

    for (i = 1; i < strsSize; i++) {
        j = 0;

        while (j < len &&
               strs[i][j] != '\0' &&
               strs[0][j] == strs[i][j]) {
            j++;
        }

        len = j;

        if (len == 0)
            return "";
    }

    strs[0][len] = '\0';
    return strs[0];
}