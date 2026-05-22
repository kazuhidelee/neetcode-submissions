class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string, char> mapping;
        for(int i = 1; i <= 26; ++i){
            mapping[to_string(i)] = 'A' + (i - 1);
        }
        vector<int> dp(s.length(), 0);
        if(mapping.count(string(1, s[0]))){
            dp[0] = 1;
        }
        for(int i = 1; i < s.length(); ++i){
            if(mapping.count(string(1, s[i]))){
                dp[i] += dp[i - 1];
            }
            string combined = s.substr(i - 1, 2);
            if(mapping.count(combined)){
                if(i == 1){
                    dp[i] += 1;
                }else{
                    dp[i] += dp[i - 2];
                }   
            }
        }
        return dp[s.length() - 1];

    }
};
