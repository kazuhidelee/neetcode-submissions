class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row_set;
        unordered_map<int, unordered_set<char>> col_set;
        unordered_map<int, unordered_set<char>> area_set;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board.size(); ++j){
                if(board[i][j] != '.'){
                    if(row_set[i].find(board[i][j]) != row_set[i].end()){
                        return false;
                    }
                    if(col_set[j].find(board[i][j]) != col_set[j].end()){
                        return false;
                    }
                    int area = (i / 3) * 9 + j / 3;
                    if(area_set[area].find(board[i][j]) != area_set[area].end()){
                        return false;
                    }
                    row_set[i].insert(board[i][j]);
                    col_set[j].insert(board[i][j]);
                    area_set[area].insert(board[i][j]);

                }
            }
        }
        return true;


    }
};
