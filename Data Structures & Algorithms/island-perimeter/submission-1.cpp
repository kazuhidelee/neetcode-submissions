class Solution {
public:
    int sides(vector<vector<int>>& grid, int x, int y){
        int side = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto dir: dirs){
            int new_x = dir[0] + x;
            int new_y = dir[1] + y;
            if(new_x >= grid.size() || new_y >= grid[0].size() || new_x < 0 || new_y < 0){
                side++;
            }else if(grid[new_x][new_y] == 0){
                side++;
            }
        }
        return side;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        queue<vector<int>> bfs;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    bfs.push({i, j});
                    grid[i][j] = -1;
                    perimeter += sides(grid, i, j);
                    while(!bfs.empty()){
                        int curr_x = bfs.front()[0];
                        int curr_y = bfs.front()[1];
                        bfs.pop();

                        for(auto dir: dirs){
                            int new_x = dir[0] + curr_x;
                            int new_y = dir[1] + curr_y;
                            if(new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size()){
                                if(grid[new_x][new_y] == 1){
                                    bfs.push({new_x, new_y});
                                    grid[new_x][new_y] = -1;
                                    perimeter += sides(grid, new_x, new_y);
                                }
                            }
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};