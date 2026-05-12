class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); ++i){
            swap(nums[i], nums[index]);
            backtrack(res, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};
