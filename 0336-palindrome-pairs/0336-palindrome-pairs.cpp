class Solution {
    struct Node {
        int next[26];
        int wordIndex;
        vector<int> palindrome;

        Node() {
            fill(next, next + 26, -1);
            wordIndex = -1;
        }
    };

    vector<Node> trie;

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void insert(const string& word, int index) {
        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if (trie[node].next[c] == -1) {
                trie[node].next[c] = trie.size();
                trie.emplace_back();
            }
            if (isPalindrome(word, 0, i)) {
                trie[node].palindrome.push_back(index);
            }

            node = trie[node].next[c];
        }

        trie[node].wordIndex = index;
        trie[node].palindrome.push_back(index);
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        trie.clear();
        trie.emplace_back();
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];

            int node = 0;
            bool failed = false;

            for (int j = 0; j < word.size(); j++) {
                if (trie[node].wordIndex != -1 &&
                    trie[node].wordIndex != i &&
                    isPalindrome(word, j, word.size() - 1)) {

                    ans.push_back({
                        i,
                        trie[node].wordIndex
                    });
                }

                int c = word[j] - 'a';

                if (trie[node].next[c] == -1) {
                    failed = true;
                    break;
                }

                node = trie[node].next[c];
            }

            if (failed)
                continue;
            for (int index : trie[node].palindrome) {
                if (index != i) {
                    ans.push_back({i, index});
                }
            }
        }

        return ans;
    }
};