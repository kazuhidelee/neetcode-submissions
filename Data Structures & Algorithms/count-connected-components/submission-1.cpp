class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                queue<int> bfs;
                bfs.push(node);
                visit[node] = true;
                while(!bfs.empty()){
                    int curr = bfs.front();
                    bfs.pop();
                    for(int i: adj[curr]){
                        if(!visit[i]){
                            bfs.push(i);
                            visit[i] = true;
                        }
                    }
                }
                res++;
            }
        }
        return res;
    }
};