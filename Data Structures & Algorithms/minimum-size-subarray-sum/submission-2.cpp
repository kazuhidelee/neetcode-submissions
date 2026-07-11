class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int arr_sum = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); ++r){
            arr_sum += nums[r];
            while(arr_sum >= target){
                res = min(res, r - l + 1);
                arr_sum -= nums[l];
                ++l;
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};