class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int tank = 0;
        int total_gas = 0;
        int total_cost = 0;
        int res = 0;
        for(int i = 0; i < n; ++i){
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i];
            tank -= cost[i];
            if(tank < 0){
                res = i + 1;
                tank = 0;
            }
        }
        if(total_cost > total_gas) return -1;
        return res;
    }
};
