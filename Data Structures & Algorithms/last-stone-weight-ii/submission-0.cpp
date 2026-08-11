class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for(int i: stones){
            total += i;
        }
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int w: stones){
            for(int i = target; i >= w; --i){
                dp[i] = dp[i] || dp[i - w];
            }
        }
        int sumA = 0;
        for(int i = target; i >= 0; --i){
            if(dp[i]){
                sumA = i;
                break;
            }
        }

        int sumB = total - sumA;

        return abs(sumA - sumB);
    }
};