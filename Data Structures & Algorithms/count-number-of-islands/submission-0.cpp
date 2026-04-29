class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1,}, {0, 1}};
        int num = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1'){
                    queue<pair<int, int>> bfs;
                    bfs.push({i, j});
                    grid[i][j] = '0';
                    while(!bfs.empty()){
                        auto curr = bfs.front();
                        bfs.pop();
                        for(auto dir: directions){
                            int x = curr.first + dir.first;
                            int y = curr.second + dir.second;
                            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[i].size() && grid[x][y] == '1'){
                                bfs.push({x, y});
                                grid[x][y] = '0';
                            }
                        }
                    }
                    num++;
                }
            }
        }
        return num;
    }
};
