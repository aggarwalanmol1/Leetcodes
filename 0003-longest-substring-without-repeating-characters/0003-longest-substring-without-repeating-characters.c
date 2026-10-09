int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];

    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int start = 0;
    int maxLength = 0;

    for (int end = 0; s[end] != '\0'; end++) {

        unsigned char ch = (unsigned char)s[end];

        if (lastIndex[ch] >= start)
            start = lastIndex[ch] + 1;

        lastIndex[ch] = end;

        int currentLength = end - start + 1;

        if (currentLength > maxLength)
            maxLength = currentLength;
    }

    return maxLength;
}