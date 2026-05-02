class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int r, int c){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if(board[r][c] != word[index]) return false;
        if(index == word.length() - 1) return true;
        char temp = board[r][c];
        board[r][c] = '_';

        bool up = dfs(board, word, index + 1, r - 1, c); 
        bool left = dfs(board, word, index + 1, r, c - 1); 
        bool down = dfs(board, word, index + 1, r + 1, c); 
        bool right = dfs(board, word, index + 1, r, c + 1);  

        board[r][c] = temp;

        return up || left || down || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[index]){
                    if(dfs(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
       
    }
};
