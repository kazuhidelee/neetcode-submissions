class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // src, dst, cost
        unordered_map<int, unordered_map<int, int>> adj;
        for(vector<int> f: flights){
            adj[f[0]][f[1]] = f[2];
        }
        // cost, node
        priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
        pq.push({0, src});
        unordered_set<int> visited;
        visited.insert(src);
        int total_cost = 0;
        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            pq.pop();
            int curr_cost = curr.first;
            int curr_node = curr.second;
            // cout << "cost: " << curr_cost << " node: " << curr_node << endl;
            visited.insert(curr_node);
            total_cost = curr_cost;
            if(curr_node == dst) return total_cost;
            for(auto a: adj[curr_node]){
                int new_cost = curr_cost + a.second;
                int new_node = a.first;
                if(visited.count(new_node)) continue;
                if(k == 0 && new_node != dst) continue;
                pq.push({new_cost, new_node});
            }
            k--;
        }
        return -1;
    }
};
