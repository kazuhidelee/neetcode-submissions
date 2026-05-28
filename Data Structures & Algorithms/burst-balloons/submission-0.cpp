class Solution {
public:
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>> &memo){
        if(l > r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        int res = 0;
        for(int i = l; i <= r; ++i){
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(nums, l, i - 1, memo) + dfs(nums, i + 1, r, memo);
            res = max(res, coins);
        }
        memo[l][r] = res;
        return memo[l][r];
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, 1, nums.size() - 2, memo);
    }
};
