class Solution {
public:
    int get_dist(vector<int> &x, vector<int> &y){
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        pq.push({0, 0});
        int cost = 0;
        while(!pq.empty()){
            int curr_cost = pq.top().first;
            int curr_index = pq.top().second;
            // cout << curr_cost << " " << curr_index << endl;
            pq.pop();
            if(visited.count(curr_index)) continue;
            cost += curr_cost;
            
            visited.insert(curr_index);
            for(int i = 0; i < points.size(); ++i){ 
                if(visited.count(i)) continue;
                int new_cost = get_dist(points[curr_index], points[i]);
                pq.push({new_cost, i});
            }
        }
        return cost;

    }
};
