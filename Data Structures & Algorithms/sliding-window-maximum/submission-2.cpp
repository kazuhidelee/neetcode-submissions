class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        // front is biggest val -> small;
        deque<int> dp;
        for(int r = 0; r < nums.size(); ++r){
           while(!dp.empty() && nums[r] > nums[dp.back()]){
            dp.pop_back();
           }
           while(!dp.empty() && dp.front() < r - k + 1){
            dp.pop_front();
           }
           dp.push_back(r);
           if(r >= k - 1) res.push_back(nums[dp.front()]);
        }
        return res;
    }
};
