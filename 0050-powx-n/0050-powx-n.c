 double myPow(double x, int n) {

    long long exp = n;
    double ans = 1.0;

    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }

    while (exp > 0) {

        if (exp % 2 == 1)
            ans *= x;

        x *= x;
        exp /= 2;
    }

    return ans;
}