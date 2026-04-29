class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto& t: times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            graph[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // time : node
        pq.push({0, k});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int time = p.first;
            int u = p.second;
            // not minimal distance
            if(time > dist[u]) continue;

            for(auto temp: graph[u]){
                int v = temp.first;
                int w = temp.second;
                if(dist[v] > time + w){
                    dist[v] = time + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(dist[i] == INT_MAX) return -1;
            ans =  max(ans, dist[i]);
        }
        return ans;
    }
};
