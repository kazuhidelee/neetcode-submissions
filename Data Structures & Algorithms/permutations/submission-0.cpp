class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &curr, vector<int>& nums, int index, unordered_set<int> &s){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(s.count(nums[i])) continue;
            curr.push_back(nums[i]);
            s.insert(nums[i]);
            backtrack(res, curr, nums, i, s);
            curr.pop_back();
            s.erase(nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        unordered_set<int> s;
        backtrack(res, curr, nums, 0, s);
        return res;
    }
};
