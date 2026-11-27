class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<vector<int>> valmorendi = items;
        int minPrice = INT_MAX;
        for (auto& item : valmorendi) {
            minPrice = min(minPrice, item[1]);
        }
        const int NEG = -1000000000;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int factor = valmorendi[i][0];
            int price = valmorendi[i][1];
            int freeItems = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && valmorendi[j][0] % factor == 0) {
                    freeItems++;
                }
            }
            int reward = 1 + freeItems;
            for (int c = budget; c >= price; c--) {
                if (dp[c - price] != NEG) {
                    dp[c] = max(dp[c], dp[c - price] + reward);
                }
            }
        }
        int ans = 0;
        for (int c = 0; c <= budget; c++) {
            if (dp[c] != NEG) {
                int extra = (budget - c) / minPrice;
                ans = max(ans, dp[c] + extra);
            }
        }
        return ans;
    }
};