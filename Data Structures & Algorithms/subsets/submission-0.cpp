class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int> curr, int start){
        res.push_back(curr);
        for(int i = start; i < nums.size(); ++i){
            curr.push_back(nums[i]);
            backtrack(res, nums, curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> curr;
        backtrack(res, nums, curr, 0);
        return res;
    }
};
