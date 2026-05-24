class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            curr_sum = max(curr_sum + nums[i], nums[i]);
            res = max(curr_sum, res);
        }
        return res;
    }
};
