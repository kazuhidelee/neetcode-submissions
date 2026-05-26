class Solution {
public:
    bool dfs(int processed, int curr, int tank, vector<int>& gas, vector<int>& cost){
        if(processed == gas.size()) return true;
        tank += gas[curr];
        tank -= cost[curr];
        if(tank < 0) return false;
        processed++;
        int next = (curr + 1) % gas.size();
        return dfs(processed, next, tank, gas, cost);
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        for(int i = 0; i < n; ++i){
            if(cost[i] <= gas[i]){
                if(dfs(0, i, 0, gas, cost)) return i;
            }
        }

        return -1;
    }
};
