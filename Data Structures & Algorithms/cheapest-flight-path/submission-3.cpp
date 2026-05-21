class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // src, dst, cost
        unordered_map<int, unordered_map<int, int>> adj;
        for(vector<int> f: flights){
            adj[f[0]][f[1]] = f[2];
        }
        // cost, node, visited
        priority_queue<tuple<int ,int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, src, 0});
        int total_cost = 0;
        while(!pq.empty()){
            auto [curr_cost, curr_node, num_nodes] = pq.top();
            pq.pop();
            // cout << "cost: " << curr_cost << " node: " << curr_node << endl;
            total_cost = curr_cost;
            if(curr_node == dst) return total_cost;
            for(auto a: adj[curr_node]){
                int new_cost = curr_cost + a.second;
                int new_node = a.first;
                int new_num = num_nodes + 1;
                if(new_num > k + 1) continue;
                pq.push({new_cost, new_node, new_num});
            }
        }
        return -1;
    }
};
