class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            graph[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        unordered_set<int> visited;
        int ans = 0;

        while (!pq.empty()) {
            auto [time, u] = pq.top(); pq.pop();
            if (visited.count(u)) continue;

            visited.insert(u);
            ans = time;

            for (auto& [v, w] : graph[u]) {
                if (!visited.count(v)) {
                    pq.push({time + w, v});
                }
            }
        }

        return visited.size() == n ? ans : -1;
    }
};
