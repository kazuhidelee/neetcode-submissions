class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int pivot = nums[r];
            int ptr = l;
            for(int i = l; i < r; ++i){
                if(nums[i] <= pivot){
                    swap(nums[i], nums[ptr]);
                    ptr++;
                }
            }
            swap(nums[ptr], nums[r]);
            if(ptr == index){
                return nums[ptr];
            }else if(ptr > index){
                r = ptr - 1;
            }else{
                l = ptr + 1;
            }

        }
        return nums[r];
    }
};
