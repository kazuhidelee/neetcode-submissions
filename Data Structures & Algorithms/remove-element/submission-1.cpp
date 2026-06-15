class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            if(nums[i] == val){
                ++res;
                while(i < j && nums[j] == val){
                    --j;
                    ++res;
                }
                swap(nums[i], nums[j]);
                --j;
            }
            ++i;
        }

        return nums.size() - res;
    }
};