class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            int target = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                if(nums[l] + nums[r] == target){
                    res.push_back({nums[i], nums[l], nums[r]});
                    int curr_l = nums[l];
                    int curr_r = nums[r];
                    while(l < r && curr_l == nums[l]) ++l;
                    while(l < r && curr_r == nums[r]) --r;
                }else if(nums[l] + nums[r] < target){
                    ++l;
                }else{
                    --r;
                }
            }

        }
        return res;
    }
};
