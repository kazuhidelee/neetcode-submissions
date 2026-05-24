class Solution {
public:
    int backtracking(int target, int curr, int index, vector<int>& nums){
        if(index == nums.size()){
            if(curr == target) return 1;
            return 0;
        }
        int total = 0;
        total += backtracking(target, curr + nums[index], index + 1, nums);
        total += backtracking(target, curr - nums[index], index + 1, nums);
        return total;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(target, 0, 0, nums);
    }
};
