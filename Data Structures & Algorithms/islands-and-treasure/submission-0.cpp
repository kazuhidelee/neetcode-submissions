class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int ,int>> bfs;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    bfs.push({i, j});
                }
                
            }
        }
        int distance = 1;
        while(!bfs.empty()){
            int level = bfs.size();
            for(int i = 0; i < level; ++i){
                auto curr = bfs.front();
                bfs.pop();
                for(auto dir: directions){
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == INT_MAX){
                        grid[x][y] = distance;
                        bfs.push({x, y});
                    }
                }
            }
            ++distance;
        }
    }
};
