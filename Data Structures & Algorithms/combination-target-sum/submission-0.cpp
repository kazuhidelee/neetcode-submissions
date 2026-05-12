class Solution {
public:
    void backtrack(vector<int>& nums, int target, int curr_sum, int index, vector<int> &curr, vector<vector<int>>&res){
        if(curr_sum == target){
            res.push_back(curr);
            return;
        }
        if(curr_sum > target) return;

        for(int i = index; i < nums.size(); ++i){
            curr.push_back(nums[i]);
            backtrack(nums, target, curr_sum + nums[i], i, curr, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, target, 0, 0, curr, res);
        return res;
    }
};
