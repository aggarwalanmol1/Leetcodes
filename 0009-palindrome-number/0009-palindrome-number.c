bool isPalindrome(int x) {
    // Negative numbers are not palindrome
    if (x < 0)
        return false;

    int original = x;
    int reverse = 0;

    while (x != 0) {
        int digit = x % 10;

        // Overflow check
        if (reverse > INT_MAX / 10)
            return false;

        reverse = reverse * 10 + digit;
        x /= 10;
    }

    return original == reverse;
}