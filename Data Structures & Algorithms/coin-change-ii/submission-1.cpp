class Solution {
public:
    unordered_map<int, unordered_map<int, int>> cache;
    int dfs(int amount, int curr, vector<int>& coins, int starting){
        if(cache[curr].count(starting)) return cache[curr][starting];
        if(curr == amount) return 1;
        if(curr > amount) return 0;

        int total = 0;

        for(int i = starting; i < coins.size(); ++i){
            total += dfs(amount, curr + coins[i], coins, i);
        }
        cache[curr][starting] = total;
        return total;
    }
    int change(int amount, vector<int>& coins) {
        return dfs(amount, 0, coins, 0);
    }
};
