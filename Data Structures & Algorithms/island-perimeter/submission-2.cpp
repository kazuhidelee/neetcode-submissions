class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    for(auto d: dirs){
                        int x = i + d[0];
                        int y = j + d[1];
                        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
                            ++perimeter;
                        }else if(grid[x][y] == 0){
                            ++perimeter;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};