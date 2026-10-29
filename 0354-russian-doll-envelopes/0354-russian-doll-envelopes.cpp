class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            int h = envelope[1];
            auto it = lower_bound(heights.begin(), heights.end(), h);
            if (it == heights.end())
                heights.push_back(h);
            else
                *it = h;
        }
        return heights.size();
    }
};