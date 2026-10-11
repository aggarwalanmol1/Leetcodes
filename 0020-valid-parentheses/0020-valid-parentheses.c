#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char *s) {
    int n = strlen(s);

    char *stack = (char *)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        }
        else {

            if (top == -1) {
                free(stack);
                return false;
            }

            char ch = stack[top--];

            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool ans = (top == -1);
    free(stack);

    return ans;
}