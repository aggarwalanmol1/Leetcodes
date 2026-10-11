#include <stdbool.h>

bool isMatch(char *s, char *p) {

    int i = 0;
    int j = 0;

    int star = -1;
    int match = 0;

    while (s[i]) {

        // Characters match or '?'
        if (p[j] == '?' || p[j] == s[i]) {
            i++;
            j++;
        }

        // Found '*'
        else if (p[j] == '*') {
            star = j;
            match = i;
            j++;
        }

        // Backtrack to previous '*'
        else if (star != -1) {
            j = star + 1;
            match++;
            i = match;
        }

        // No match
        else {
            return false;
        }
    }

    // Remaining characters in pattern must all be '*'
    while (p[j] == '*')
        j++;

    return p[j] == '\0';
}