class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int n = board.size() - 1;
        int m = board[0].size() - 1;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(board[i][j] == 'O'){
                    queue<pair<int, int>> bfs;
                    queue<pair<int, int>> processed;
                    bool has_boarder = false;
                    bfs.push({i, j});
                    while(!bfs.empty()){
                        pair<int, int> curr = bfs.front();
                        processed.push(curr);
                        if(curr.first == n || curr.first == 0 || curr.second == m || curr.second == 0) has_boarder = true;
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

                    if(!has_boarder){
                        while(!processed.empty()){
                            pair<int, int> curr = processed.front();
                            processed.pop();
                            board[curr.first][curr.second] = 'X';
                        }
                    }
                }
                
                
            }
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(board[i][j] == '_'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
