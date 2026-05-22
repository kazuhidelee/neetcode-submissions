class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ending = nums[0];
        int min_ending = nums[0];
        int max_product = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int temp = max_ending;
            max_ending = max(nums[i], max(max_ending * nums[i], min_ending * nums[i]));
            min_ending = min(nums[i], min(min_ending * nums[i], temp * nums[i]));
            max_product = max(max_product, max_ending);
            cout << max_ending <<" " << min_ending << endl;
        }
        return max_product;
    }
};
