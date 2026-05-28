class Solution {
public:
    int dfs(string &s, string &t, int i, int j, vector<vector<int>> &memo){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int exclude = 0;
        int include = 0;
        if(s[i] == t[j]){
            include = dfs(s, t, i + 1, j + 1, memo);
        }
        exclude = dfs(s, t, i + 1, j, memo);
        memo[i][j] = exclude + include;
        return memo[i][j];
    }
    int numDistinct(string s, string t) {
        if(t.length() > s.length()) return 0;
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
        string curr = "";
        return dfs(s, t, 0, 0, memo);
    }
};
