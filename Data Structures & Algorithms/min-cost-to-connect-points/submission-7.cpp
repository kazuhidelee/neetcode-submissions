class Solution {
public:
    int get_dist(vector<int> &x, vector<int> &y){
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> dist(points.size(), INT_MAX);
        vector<int> visited(points.size(), 0);
        int i = 0;
        int curr = 0;
        int cost = 0;
        dist[0] = 0;
        while(i < points.size()){
            cost += dist[curr];
            visited[curr] = 1;
            cout << dist[curr] << endl;
            int min_dist = INT_MAX;
            int next;
            for(int i = 0; i < points.size(); ++i){
                if(visited[i] == 1) continue;
                int new_dist = get_dist(points[curr], points[i]);
                dist[i] = min(dist[i], new_dist);
                if(dist[i] < min_dist){
                    next = i;
                    min_dist = dist[i];
                }
            }
            ++i; 
            curr = next; 
        }
        return cost;

    }
};
