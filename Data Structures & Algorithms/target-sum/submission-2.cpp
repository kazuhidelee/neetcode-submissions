class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    int backtracking(int target, int curr, int index, vector<int>& nums){
        if(memo[curr].count(index)){
            return memo[curr][index];
        }
        if(index == nums.size()){
            if(curr == target) return 1;
            return 0;
        }
        int total = 0;
        total += backtracking(target, curr + nums[index], index + 1, nums);
        total += backtracking(target, curr - nums[index], index + 1, nums);
        memo[curr][index] = total; 
        return total;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(target, 0, 0, nums);
    }
};
