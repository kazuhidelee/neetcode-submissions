class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int n = board.size() - 1;
        int m = board[0].size() - 1;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(board[i][j] == 'O' && (i == n || i == 0 || j == m || j == 0)){
                    board[i][j] = '_';
                    queue<pair<int, int>> bfs;
                    bfs.push({i, j});
                    while(!bfs.empty()){
                        pair<int, int> curr = bfs.front();
                        bfs.pop();
                        for(auto d: dirs){
                            int x = curr.first + d.first;
                            int y = curr.second + d.second;
                            if(x > n || x < 0 || y > m || y < 0) continue;
                            if(board[x][y] == 'O'){
                                board[x][y] = '_';
                                bfs.push({x, y});
                            }
                        }
                    }
                }
                
                
            }
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '_'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
