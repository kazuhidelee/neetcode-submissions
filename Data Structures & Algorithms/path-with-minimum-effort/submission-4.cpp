class Solution {
public:
    struct state{
        int effort;
        int x;
        int y;
    };
    struct Compare{
        bool operator()(const state &a, const state &b){
            return a.effort > b.effort;
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), 0));
        priority_queue<state, vector<state>, Compare> bfs;
        bfs.push({0, 0, 0});
        while(!bfs.empty()){
            auto curr = bfs.top();
            bfs.pop();
            int curr_x = curr.x;
            int curr_y = curr.y;
            int curr_e = curr.effort;
            if(visited[curr_x][curr_y] == 1) continue;
            visited[curr_x][curr_y] =1;
            if(curr_x == heights.size() - 1 && curr_y == heights[0].size() - 1){
                return curr_e;
            }

            for(vector<int> &d: dirs){
                int new_x = curr_x + d[0];
                int new_y = curr_y + d[1];
                if(new_x < heights.size() && new_x >= 0 && new_y < heights[0].size() && new_y >= 0){
                    if(visited[new_x][new_y] != 1){
                        int new_e = max(curr_e, abs(heights[new_x][new_y] - heights[curr_x][curr_y]));
                        bfs.push({new_e, new_x, new_y});
                    }
                }
                
            }
        }
        return 0;
    }
};