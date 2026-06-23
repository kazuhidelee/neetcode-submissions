class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        int i = 0;
        int j = k - 1;

        int p = k;
        int q = nums.size() - 1;
        while(i < j || p < q){
            if(i < j){
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
            if(p < q){
                swap(nums[p], nums[q]);
                ++p;
                --q;
            }
        }

    }
};