#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {

    char *current = (char *)malloc(5000);
    strcpy(current, "1");

    for (int k = 2; k <= n; k++) {

        char *next = (char *)malloc(5000);
        int idx = 0;

        int len = strlen(current);

        for (int i = 0; i < len;) {

            int count = 1;

            while (i + 1 < len && current[i] == current[i + 1]) {
                count++;
                i++;
            }

            idx += sprintf(next + idx, "%d%c", count, current[i]);

            i++;
        }

        next[idx] = '\0';

        free(current);
        current = next;
    }

    return current;
}