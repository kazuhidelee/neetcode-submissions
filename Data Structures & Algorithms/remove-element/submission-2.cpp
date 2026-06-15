class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            if(nums[i] == val){
                swap(nums[i], nums[j]);
                --j;
            }else{
                ++res;
                ++i;
            }
        }

        return res;
    }
};