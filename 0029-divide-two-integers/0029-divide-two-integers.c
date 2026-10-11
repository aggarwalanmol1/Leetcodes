#include <limits.h>

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign of result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert to positive long long to avoid overflow
    long long dvd = llabs((long long)dividend);
long long dvs = llabs((long long)divisor);

    long long result = 0;

    while (dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;

        // Double divisor until it is just smaller than dividend
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        result += multiple;
    }

if (sign < 0)
        result = -result;

    return (int)result;
}