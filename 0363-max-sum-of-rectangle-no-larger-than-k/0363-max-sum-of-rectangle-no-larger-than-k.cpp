class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        for (int left = 0; left < n; left++) {
            vector<int> sums(m, 0);
            for (int right = left; right < n; right++) {
                for (int row = 0; row < m; row++) {
                    sums[row] += matrix[row][right];
                }                set<int> prefix;
                prefix.insert(0);
                int currentSum = 0;
                for (int x : sums) {
                    currentSum += x;
                    auto it = prefix.lower_bound(currentSum - k);
                    if (it != prefix.end()) {
                        ans = max(ans, currentSum - *it);
                    }
                    prefix.insert(currentSum);
                }
                if (ans == k) return k;
            }
        }
        return ans;
    }
};