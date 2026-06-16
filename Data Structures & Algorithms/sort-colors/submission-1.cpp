class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int ptr = 0;
        while(ptr <= r){
            if(nums[ptr] == 2){
                swap(nums[ptr], nums[r]);
                --r;
            }else if(nums[ptr] == 0){
                swap(nums[ptr], nums[l]);
                ++l;
                ++ptr;
            }else{
                ++ptr;
            }
        }
    }
};