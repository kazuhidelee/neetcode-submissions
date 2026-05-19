class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int total = 0;
        queue<pair<int, int>> bfs;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0) continue;
                if(grid[i][j] == 2) bfs.push({i, j});
                total++;
            }
        }
        if(total == 0) return 0;
        int minute = 0;
        while(!bfs.empty()){
            int n = bfs.size();
            cout << n << endl;
            for(int i = 0; i < n; ++i){
                pair<int, int> curr = bfs.front();
                bfs.pop();
                total--;
                for(auto dir: directions){
                    int r = curr.first + dir.first;
                    int c = curr.second + dir.second;
                    if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) continue;
                    if(grid[r][c] == 1){
                        bfs.push({r, c});
                        grid[r][c] = 2;
                    }
                }

            }
            minute++;
        }
        if(total != 0) return -1;
        return minute - 1;
    }
};
