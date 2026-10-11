#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {

    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char *ans = (char *)malloc(2);
        strcpy(ans, "0");
        return ans;
    }

    int m = strlen(num1);
    int n = strlen(num2);

    int *res = (int *)calloc(m + n, sizeof(int));

    for (int i = m - 1; i >= 0; i--) {

        for (int j = n - 1; j >= 0; j--) {

            int mul = (num1[i] - '0') * (num2[j] - '0');

            int p1 = i + j;
            int p2 = i + j + 1;

            int sum = mul + res[p2];

            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    char *ans = (char *)malloc(m + n + 1);

    int k = 0;
    int i = 0;

    while (i < m + n && res[i] == 0)
        i++;

    while (i < m + n)
        ans[k++] = res[i++] + '0';

    ans[k] = '\0';

    free(res);

    return ans;
}