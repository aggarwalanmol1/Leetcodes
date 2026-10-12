class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return (int)mergeSort(prefix, 0, prefix.size(), lower, upper);
    }
private:
    long long mergeSort(vector<long long>& sums, int left, int right,
                        int lower, int upper) {
        if (right - left <= 1)
            return 0;
        int mid = left + (right - left) / 2;
        long long count = mergeSort(sums, left, mid, lower, upper)
                        + mergeSort(sums, mid, right, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long long> temp(right - left);
        int p = 0;
        for (int i = left; i < mid; i++) {
            while (j < right && sums[j] - sums[i] < lower)
                j++;
            while (k < right && sums[k] - sums[i] <= upper)
                k++;
            count += k - j;
        }
        int i = left;
        j = mid;
        while (i < mid && j < right) {
            if (sums[i] <= sums[j])
                temp[p++] = sums[i++];
            else
                temp[p++] = sums[j++];
        }
        while (i < mid) temp[p++] = sums[i++];
        while (j < right) temp[p++] = sums[j++];
        for (int x = 0; x < p; x++)
            sums[left + x] = temp[x];
        return count;
    }
};