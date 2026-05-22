class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> first;
        vector<int> second;
        for(int i = 0; i < nums.size(); ++i){
            if(i < nums.size() - 1){
                first.push_back(nums[i]);
            }
            if(i > 0){
                second.push_back(nums[i]);
            }
        }
        first[0] = nums[0];
        first[1] = max(nums[0], nums[1]);

        second[0] = nums[1];
        second[1] = max(nums[1], nums[2]);
        
        for(int i = 2; i < first.size(); ++i){
            first[i] = max(first[i - 1], first[i - 2] + first[i]);
        }
        for(int i = 2; i < second.size(); ++i){
            second[i] = max(second[i - 1], second[i - 2] + second[i]);
        }
        return max(first[first.size() - 1], second[second.size() - 1]);
    }
};
