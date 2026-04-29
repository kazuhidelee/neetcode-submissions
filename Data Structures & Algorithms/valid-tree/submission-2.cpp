class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // node -> parent
        stack<pair<int, int>> dfs;
        unordered_set<int> visited;
        dfs.push({0, -1});
        visited.insert(0);
        int parent = -1;
        while(!dfs.empty()){
            auto curr = dfs.top();
            dfs.pop();
            for(int i: adj[curr.first]){
                if (i == curr.second) continue;  
                if (visited.count(i)) return false; 
                dfs.push({i, curr.first});
                visited.insert(i); 
            }
        }
        return visited.size() == n;
    }
};
