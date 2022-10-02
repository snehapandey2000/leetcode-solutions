// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)
            return {-1, -1};
        int l = 0, r = n - 1;
        int first = l + ((r - l) >> 1);
        while ((l < r) && (first >= 0) && (first < n)) {
            if (nums[first] < target) {
                l = first + 1;
            }
            else if (nums[first] == target) {
                r = first;
            }
            else if (nums[first] > target) {
                r = first - 1;
            }
            first = l + ((r - l) >> 1);
        }
        if (first < 0 || first >= n)
            return {-1, -1};
        if (nums[first] != target)
            return {-1, -1};
        l = first, r = n - 1;
        int last = l + (((r - l) + 1) >> 1);
        while ((l < r) && (last >= 0) && (last < n)) {
            if (nums[last] == target) {
                l = last;
            }
            else if (nums[last] > target) {
                r = last - 1;
            }
            last = l + (((r - l) + 1) >> 1);
        }
        if (last < 0 || last >= n)
            return {-1, -1};
        if (nums[last] != target)
            return {-1, -1};
        if (nums[first] == target && nums[last] == target) {
            return {first, last};
        }
        else {
            return {-1, -1};
        }
    }
};