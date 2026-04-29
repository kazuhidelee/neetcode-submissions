class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) return m;

            if (nums[l] <= nums[m]) {  // left sorted
                // target within the range of the sorted array
                if (target >= nums[l] && target <= nums[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {  // right sorted
                if (target >= nums[m] && target <= nums[r]) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
