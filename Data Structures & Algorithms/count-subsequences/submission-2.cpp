class Solution {
public:
    // int dfs(string &s, string &t, int i, int j, vector<vector<int>> &memo){
    //     if(j == t.length()) return 1;
    //     if(i == s.length()) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     int exclude = 0;
    //     int include = 0;
    //     if(s[i] == t[j]){
    //         include = dfs(s, t, i + 1, j + 1, memo);
    //     }
    //     exclude = dfs(s, t, i + 1, j, memo);
    //     memo[i][j] = exclude + include;
    //     return memo[i][j];
    // }
    int numDistinct(string s, string t) {
        if(t.length() > s.length()) return 0;
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
        for(int i = s.length(); i >= 0; --i){
            for(int j = t.length(); j >= 0; --j){
                if(j == t.length()){
                    dp[i][j] = 1;
                    continue;
                } 
                if(i == s.length()){
                    dp[i][j] = 0;
                    continue;
                } 
                if(s[i] == t[j]){
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }else{
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
