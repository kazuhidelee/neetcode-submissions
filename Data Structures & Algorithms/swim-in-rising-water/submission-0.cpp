class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1 ,0}, {0, -1}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({grid[0][0], 0});
        int n = grid.size();
        int curr_r = 0;
        int curr_c = 0;
        while(!pq.empty()){
            int curr_cost = pq.top().first;
            int curr_r = pq.top().second / n;
            int curr_c = pq.top().second % n;
            pq.pop();
            if(curr_r == n - 1 && curr_c == n - 1) return curr_cost;
            if(grid[curr_r][curr_c] == -1) continue;
            grid[curr_r][curr_c] = -1;

            for(auto d: dirs){
                int new_r = curr_r + d[0];
                int new_c = curr_c + d[1];
                if(new_r < 0 || new_c < 0 || new_r >= n || new_c >= n) continue;
                if(grid[new_r][new_c] == -1) continue;
                int index = new_r * n + new_c;
                int cost = max(curr_cost, grid[new_r][new_c]);
                pq.push({cost, index});
            }
        }
        return 0;
    }
};
