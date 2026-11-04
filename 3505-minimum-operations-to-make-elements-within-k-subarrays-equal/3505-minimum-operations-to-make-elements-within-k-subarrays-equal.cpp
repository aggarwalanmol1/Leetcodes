class Solution {
private:
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;
    void rebalance() {
        int total = low.size() + high.size();
        int required = (total + 1) / 2;
        while ((int)low.size() > required) {
            auto it = prev(low.end());
            long long val = *it;
            low.erase(it);
            sumLow -= val;
            high.insert(val);
            sumHigh += val;
        }
        while ((int)low.size() < required) {
            auto it = high.begin();
            long long val = *it;
            high.erase(it);
            sumHigh -= val;
            low.insert(val);
            sumLow += val;
        }
    }
    void add(long long val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }
        rebalance();
    }
    void remove(long long val) {
        auto it = low.find(val);
        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }
        rebalance();
    }
    long long getCost() {
        long long median = *low.rbegin();
        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        cost[0] = getCost();
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        for (int t = 1; t <= k; t++) {
            for (int i = 1; i <= n; i++) {
                dp[t][i] = dp[t][i - 1];
                if (i >= x) {
                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][i - x] + cost[i - x]
                    );
                }
            }
        }
        return dp[k][n];
    }
};