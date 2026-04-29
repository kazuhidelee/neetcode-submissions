class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(), 1);
        int product = 1;
        for(int i = 0; i < nums.size(); ++i){
            pre[i] = pre[i] * product;
            product *= nums[i];
            cout << pre[i] << endl;
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; --i){
            pre[i] = pre[i] * product;
            product *= nums[i];
        }
        return pre;
    }
};
