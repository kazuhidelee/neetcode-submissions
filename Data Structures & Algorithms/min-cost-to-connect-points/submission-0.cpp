class Solution {
public:
    int get_distance(vector<int> &x, vector<int> &y){
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(points.size(), 0);
        pq.push({0, 0});
        int res = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            int curr_weight = curr.first;
            int curr_index = curr.second;
            pq.pop();
            if(visited[curr_index] == 1) continue;
            visited[curr_index] = 1;
            res += curr_weight;
            for(int i = 0; i < points.size(); ++i){
                if(visited[i] == 1) continue;
                pq.push({get_distance(points[curr_index], points[i]), i});
                
            }

        } 
        return res;

    }
};
