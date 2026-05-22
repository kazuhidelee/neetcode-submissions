class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, 0);
        dp[0] = true;
        unordered_set<string> words;
        for(string s: wordDict){
            words.insert(s);
        }
        for(int i = 1; i < s.length() + 1; ++i){
            for(int j = 0; j <= i; ++j){
                if(dp[j] && words.count(s.substr(j, i - j))){
                    cout << i << ", " << j << endl;
                    dp[i] = true;
                }
            }
        }
        return dp[s.length()];
    }
};
