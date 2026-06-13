class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = 0;
        for(int i = 0; i <= nums.size(); ++i){
            temp ^= i;
        }
        for(int i = 0; i < nums.size(); ++i){
            temp ^= nums[i];
        }
        return temp;
    }
};
