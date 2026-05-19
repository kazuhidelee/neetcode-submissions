class Solution {
public:
    bool verifier(vector<vector<char>> &board, int r, int c){
        int n = board.size();
        // down
        for(int i = r + 1; i < n; ++i){
            if(board[i][c] == 'Q'){
                return false;
            } 
        }
        // up
        for(int i = r - 1; i >= 0; --i){
            if(board[i][c] == 'Q'){
                return false;
            } 
        }
        // left
        for(int i = c - 1; i >= 0; --i){
            if(board[r][i] == 'Q'){
                return false;
            } 
        }
        // right
        for(int i = c + 1; i < n; ++i){
            if(board[r][i] == 'Q'){
                return false;
            } 
        }
        // left up diagonal 
        int i = r - 1;
        int j = c - 1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            } 
            --i;
            --j;
        }
        // right up diagonal 
        i = r - 1;
        j = c + 1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            --i;
            ++j;
        }
        // left down diagonal 
        i = r + 1;
        j = c - 1;
        while(i < n && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            ++i;
            --j;
        }
        // right down diagonal 
        i = r + 1;
        j = c + 1;
        while(i < n && j < n){
            if(board[i][j] == 'Q'){
                cout << "here6" << endl;
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }

    vector<string> print_board(vector<vector<char>> &board){
        vector<string> res;
        for(int i = 0; i < board.size(); ++i){
            string row = "";
            for(int j = 0; j < board.size(); ++j){
                row.push_back(board[i][j]);
            }
            res.push_back(row);
        }
        return res;
    }

    void backtracking(vector<vector<char>> &board, int row, vector<vector<string>> &res){
        if(row == board.size()){
            res.push_back(print_board(board));
            return;
        }

        for(int i = 0; i < board.size(); ++i){
            cout << row << ", " << i << endl;
            board[row][i] = 'Q';
            if(verifier(board, row, i)){
                backtracking(board, row + 1, res);
            }
            board[row][i] = '.';
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> res;
        backtracking(board, 0, res);
        return res;

    }
};
