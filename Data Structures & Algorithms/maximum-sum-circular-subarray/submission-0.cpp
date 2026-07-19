class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        deque<pair<int, int>> seen;
        seen.push_back({0, 0});
        int n = nums.size();
        int prefix_sum = 0;
        int res = INT_MIN;
        for(int i = 1; i < nums.size() * 2; ++i){
            prefix_sum += nums[i % n];
            while(!seen.empty() && i - seen.front().second > n){
                seen.pop_front();
            }
            if(!seen.empty()){
                res = max(res, prefix_sum - seen.front().first);
            }
            while(!seen.empty() && prefix_sum < seen.back().first){
                seen.pop_back();
            }
            seen.push_back({prefix_sum, i});
        }
        return res;
    }
};