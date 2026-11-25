class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), rank(n), temp(n);
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];
                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;
                return ra < rb;
            });
            temp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];
                bool different = rank[a] != rank[b];
                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;
                if (ra != rb)
                    different = true;
                temp[b] = temp[a] + different;
            }
            rank = temp;
            if (rank[sa[n - 1]] == n - 1)
                break;
        }
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;
        vector<int> lcp(n, 0);
        int h = 0;
        for (int i = 0; i < n; i++) {
            int r = pos[i];
            if (r == 0)
                continue;
            int j = sa[r - 1];
            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }
            lcp[r] = h;
            if (h > 0)
                h--;
        }
        int ans = n;
        for (int r = 0; r < n; r++) {
            int start = sa[r];
            int maxLCP = lcp[r];
            if (r + 1 < n)
                maxLCP = max(maxLCP, lcp[r + 1]);
            int required = maxLCP + 1;
            if (start + required <= n)
                ans = min(ans, required);
        }
        return ans;
    }
};