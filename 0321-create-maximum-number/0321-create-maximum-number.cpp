class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> a = pickMax(nums1, i);
            vector<int> b = pickMax(nums2, k - i);
            vector<int> candidate = mergeMax(a, b);
            if (greaterVec(candidate, best))
                best = candidate;
        }
        return best;
    }
private:
    vector<int> pickMax(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;
        for (int x : nums) {
            while (drop > 0 && !st.empty() && st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }
        st.resize(k);
        return st;
    }
    vector<int> mergeMax(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {
            if (greaterSuffix(a, i, b, j))
                result.push_back(a[i++]);
            else
                result.push_back(b[j++]);
        }
        return result;
    }
    bool greaterSuffix(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i == a.size()) return false;
        return a[i] > b[j];
    }
    bool greaterVec(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (i == b.size()) return true;
            if (a[i] != b[i]) return a[i] > b[i];
        }
        return false;
    }
};