class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int rolling = 0;
        int res = 0;
        unordered_map<int, int> mapping;
        mapping[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            rolling += nums[i];
            int comp = rolling - k;
            res += mapping[comp];
            mapping[rolling]++;
        }   
        return res;
    }
};