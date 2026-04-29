class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int r = k - 1; r < nums.size(); ++r){
            int curr_max = INT_MIN;
            for(int i = r; i >= r - k + 1; --i){
                curr_max = max(nums[i], curr_max);
            }
            res.push_back(curr_max);
        }
        return res;
    }
};
