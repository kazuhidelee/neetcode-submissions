class Solution {
public:
    // bool verifier(vector<vector<char>> &board, int r, int c){
    //     int n = board.size();
    //     // up
    //     for(int i = r - 1; i >= 0; --i){
    //         if(board[i][c] == 'Q'){
    //             return false;
    //         } 
    //     }
    //     // left up diagonal 
    //     int i = r - 1;
    //     int j = c - 1;
    //     while(i >= 0 && j >= 0){
    //         if(board[i][j] == 'Q'){
    //             return false;
    //         } 
    //         --i;
    //         --j;
    //     }
    //     // right up diagonal 
    //     i = r - 1;
    //     j = c + 1;
    //     while(i >= 0 && j < n){
    //         if(board[i][j] == 'Q'){
    //             return false;
    //         }
    //         --i;
    //         ++j;
    //     }
    //     return true;
    // }

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

    void backtracking(vector<vector<char>> &board, int row, vector<vector<string>> &res, unordered_set<int> &cols, unordered_set<int> &up_left, unordered_set<int> &up_right){
        if(row == board.size()){
            res.push_back(print_board(board));
            return;
        }

        for(int i = 0; i < board.size(); ++i){
            if(cols.count(i)) continue;
            if(up_left.count(row - i)) continue;
            if(up_right.count(row + i)) continue;
            board[row][i] = 'Q';
            cols.insert(i);
            up_left.insert(row - i);
            up_right.insert(row + i);
            backtracking(board, row + 1, res, cols, up_left, up_right);
            board[row][i] = '.';
            cols.erase(i);
            up_left.erase(row - i);
            up_right.erase(row + i);
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> res;
        unordered_set<int> cols;
        unordered_set<int> up_left;
        unordered_set<int> up_right;
        backtracking(board, 0, res, cols, up_left, up_right);
        return res;

    }
};
