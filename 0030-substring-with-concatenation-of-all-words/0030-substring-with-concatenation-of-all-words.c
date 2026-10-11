#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000

typedef struct {
    char *word;
    int count;
} WordCount;

int findWord(WordCount *map, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(map[i].word, word) == 0)
            return i;
    }

    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize,
                   int* returnSize) {

    *returnSize = 0;

    if (wordsSize == 0)
        return NULL;

    int wordLen = strlen(words[0]);
    int sLen = strlen(s);

    int totalLen = wordLen * wordsSize;

    if (totalLen > sLen)
        return NULL;

    int *result = malloc(sLen * sizeof(int));

    WordCount need[MAX_WORDS];
    WordCount window[MAX_WORDS];

    int unique = 0;

    // Build frequency map of words
    for (int i = 0; i < wordsSize; i++) {

        int index = findWord(need, unique, words[i]);

        if (index == -1) {
            need[unique].word = words[i];
            need[unique].count = 1;
            unique++;
        } else {
            need[index].count++;
        }
    }

    // Try every possible offset
    for (int offset = 0; offset < wordLen; offset++) {

        int left = offset;
        int right = offset;
        int count = 0;

        // Reset window
        for (int i = 0; i < unique; i++)
            window[i].count = 0;

        while (right + wordLen <= sLen) {

            char current[wordLen + 1];

            strncpy(current, s + right, wordLen);
            current[wordLen] = '\0';

            right += wordLen;

            int index = findWord(need, unique, current);

            // Word is not required
            if (index == -1) {

                for (int i = 0; i < unique; i++)
                    window[i].count = 0;

                count = 0;
                left = right;
                continue;
            }

            window[index].count++;
            count++;

            // Too many occurrences of this word
            while (window[index].count > need[index].count) {

                char leftWord[wordLen + 1];

                strncpy(leftWord, s + left, wordLen);
                leftWord[wordLen] = '\0';

                int leftIndex =
                    findWord(need, unique, leftWord);

                window[leftIndex].count--;
                count--;
                left += wordLen;
            }

            // All words found
            if (count == wordsSize) {

                result[*returnSize] = left;
                (*returnSize)++;

                // Move left forward to search for next window
                char leftWord[wordLen + 1];

                strncpy(leftWord, s + left, wordLen);
                leftWord[wordLen] = '\0';

                int leftIndex =
                    findWord(need, unique, leftWord);

                window[leftIndex].count--;
                count--;
                left += wordLen;
            }
        }
    }

    return result;
}