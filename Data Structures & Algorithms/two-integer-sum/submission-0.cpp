class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        for(int i = 0; i < nums.size(); ++i){
            if(comp.find(target - nums[i]) != comp.end()){
                return {comp[target - nums[i]], i};
            }
            comp[nums[i]] = i;
        }
        return {};
    }
};
