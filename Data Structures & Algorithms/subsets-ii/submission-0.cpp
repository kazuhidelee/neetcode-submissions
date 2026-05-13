class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>> &res, int index){

        res.push_back(curr);

        for(int i = index; i < nums.size(); ++i){
            if(i > index && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, curr, res, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, curr, res, 0);
        return res;
    }   
};
