class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); ++i){
            total += nums[i];
        }
        if (total % 2 != 0) return false;
        int target = total/2;
        unordered_set<int> sums;
        sums.insert(0);
        for(int n: nums){
            unordered_set<int> temp = sums;
            for(int s: sums){
                if(s + n == target) return true;
                temp.insert(s + n);
            }
            sums = temp;
        }
        return false;
    }
};
