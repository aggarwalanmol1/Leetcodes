class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int ans = 2;
        for (int i = 0; i < n; i++) {
            vector<int> sub;
            for (int j = i; j < n; j++) {
                if (j - i + 1 >= 3) {
                    bool valid = true;
                    if (j == i + 2 &&
                        gcd(nums[i], nums[i + 1]) != 1) {
                        valid = false;
                    }
                    for (int x : sub) {
                        if (gcd(x, nums[j]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }
                sub.push_back(nums[j]);
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};