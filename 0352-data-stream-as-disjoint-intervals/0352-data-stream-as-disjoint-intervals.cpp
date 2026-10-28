class SummaryRanges {
private:
    set<int> nums;
public:
    SummaryRanges() {
    }
    void addNum(int value) {
        nums.insert(value);
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if (nums.empty())
            return ans;
        auto it = nums.begin();
        int start = *it;
        int end = *it;
        ++it;
        while (it != nums.end()) {
            if (*it == end + 1) {
                end = *it;
            }
            else {
                ans.push_back({start, end});
                start = *it;
                end = *it;
            }
            ++it;
        }
        ans.push_back({start, end});

        return ans;
    }
};