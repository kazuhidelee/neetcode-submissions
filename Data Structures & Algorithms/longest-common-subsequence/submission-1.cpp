class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        for(int i = 0; i < text1.size(); ++i){
            for(int j = 0; j < text2.size(); ++j){
                int res = INT_MIN;
                if(i - 1 >= 0){
                    res = max(res, dp[i-1][j]);
                }
                if(j - 1 >= 0){
                    res = max(res, dp[i][j-1]);
                }
                if(res == INT_MIN) res = 0;
                if(text1[i] == text2[j]){
                    dp[i][j] = 1;
                    if(i - 1 >= 0 && j - 1 >= 0){
                        dp[i][j] += dp[i-1][j-1];
                    } 
                }else{
                    dp[i][j] = res;
                }
                
            }
        }
        return dp[text1.length() - 1][text2.length() - 1];
    }
};