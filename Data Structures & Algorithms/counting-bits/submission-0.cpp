class Solution {
public:
    unordered_map<int, int> memo;
    int dp(int n){
        if(n == 1) return 1;
        if(n == 0) return 0;
        if(memo.find(n) != memo.end()) return memo[n];
        if(n % 2 == 0){
            memo[n] = dp(n >> 1);
        }else{
            memo[n] =  1 + dp(n >> 1);
        }
        return memo[n];
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i){
            res.push_back(dp(i));
        }
        return res;
    }
};
