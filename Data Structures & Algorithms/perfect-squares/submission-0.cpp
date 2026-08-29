class Solution {
public:
    int numSquares(int n) {
        vector<int> square_nums;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int i = 1;
        while(i <= n){
            square_nums.push_back(i * i);
            ++i;
        }

        for(int i = 0; i <= n; ++i){
            for(int num: square_nums){
                if(i - num >= 0){
                    dp[i] = min(dp[i], dp[i - num] + 1);
                }
            }
        }

        return dp[n];

    }
};