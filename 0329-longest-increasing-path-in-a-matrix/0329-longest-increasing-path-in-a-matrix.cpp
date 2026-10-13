class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp,
            int r, int c) {
        if (dp[r][c] != 0)
            return dp[r][c];
        int m = matrix.size();
        int n = matrix[0].size();
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        dp[r][c] = 1;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]) {
                dp[r][c] = max(dp[r][c],
                               1 + dfs(matrix, dp, nr, nc));
            }
        }
        return dp[r][c];
    }
};