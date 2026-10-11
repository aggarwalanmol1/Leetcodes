#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    ans[0] = -1;
    ans[1] = -1;

    // Find first occurrence
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            ans[0] = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Find last occurrence
    left = 0;
    right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            ans[1] = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}