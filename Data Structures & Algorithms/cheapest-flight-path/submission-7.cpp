class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // src, dst, cost
        unordered_map<int, unordered_map<int, int>> adj;
        vector<int> distance(n, INT_MAX);
        for(vector<int> f: flights){
            adj[f[0]][f[1]] = f[2];
        }
        // cost, node, visited
        queue<tuple<int ,int, int>> bfs;
        distance[src] = 0;
        bfs.push({0, src, 0});
        int total_cost = 0;
        while(!bfs.empty()){
            auto [curr_cost, curr_node, num_nodes] = bfs.front();
            bfs.pop();
            total_cost = curr_cost;
            for(auto a: adj[curr_node]){
                int new_cost = curr_cost + a.second;
                int new_node = a.first;
                int new_num = num_nodes + 1;
                if(new_num > k + 1) continue;
                if(new_cost < distance[new_node]){
                    distance[new_node] = min(distance[new_node], new_cost);
                    bfs.push({new_cost, new_node, new_num});
                }
            }
        }
        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};
