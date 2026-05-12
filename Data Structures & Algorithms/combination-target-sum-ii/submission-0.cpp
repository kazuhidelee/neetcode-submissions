class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int curr_sum, vector<int> &curr, vector<vector<int>> &res, int index){
        if(curr_sum == target){
            res.push_back(curr);
            return;
        }
        if(curr_sum > target) return;
        for(int i = index; i < candidates.size(); ++i){
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            backtracking(candidates, target, curr_sum + candidates[i], curr, res, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(candidates, target, 0, curr, res, 0);
        return res;
    }

};
