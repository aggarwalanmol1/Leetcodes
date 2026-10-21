class NestedIterator {
private:
    vector<int> nums;
    int index;
    void flatten(vector<NestedInteger>& nestedList) {
        for (auto& item : nestedList) {
            if (item.isInteger()) {
                nums.push_back(item.getInteger());
            } 
            else {
                vector<NestedInteger> list = item.getList();
                flatten(list);   }  } }
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        index = 0;
        flatten(nestedList);
    }
    int next() {
        return nums[index++];
    }
    bool hasNext() {
        return index < nums.size();
    }
};