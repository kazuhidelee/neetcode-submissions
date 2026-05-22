class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); ++i){
            total += nums[i];
        }
        int target = total/2;
        if (total % 2 != 0) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int n: nums){
            for(int s = target; s >= n; --s){
                dp[s] = dp[s] || dp[s - n];
            }
        }
        return dp[target];
    }
};
