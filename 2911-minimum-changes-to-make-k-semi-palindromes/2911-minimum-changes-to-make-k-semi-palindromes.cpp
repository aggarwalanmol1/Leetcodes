class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;
                    int changes = 0;
                    for (int offset = 0; offset < d; offset++) {
                        int left = i + offset;
                        int right = j - d + 1 + offset;
                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int t = 1; t <= k; t++) {
                for (int prev = 0; prev <= i - 2; prev++) {
                    if (dp[prev][t - 1] == INF)
                        continue;
                    dp[i][t] = min(
                        dp[i][t],
                        dp[prev][t - 1] + cost[prev][i - 1]
                    );
                }
            }
        }
        return dp[n][k];
    }
};