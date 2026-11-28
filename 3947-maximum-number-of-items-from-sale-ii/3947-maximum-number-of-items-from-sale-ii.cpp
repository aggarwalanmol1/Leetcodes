class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        int minPrice = INT_MAX;
        int maxFactor = 0;
        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
            maxFactor = max(maxFactor, item[0]);
        }
        vector<int> gain(maxFactor + 1, 0);
        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--; 
        }
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        long long ans = 0;
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];
            if (price >= 2LL * minPrice)
                break;
            int available = gain[factor];
            int take = min(available, budget / price);
            ans += 2LL * take;
            budget -= take * price;
        }
        ans += budget / minPrice;
        return (int)ans;
    }
};