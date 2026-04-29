class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // verify rows
        for(int i = 0; i < board.size(); ++i){
            unordered_set<int> s;
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) != s.end()){
                        return false;
                    }else{
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        // verify cols
        for(int j = 0; j < board[0].size(); ++j){
            unordered_set<int> s;
            for(int i = 0; i < board.size(); ++i){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) != s.end()){
                        return false;
                    }else{
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        for(int starting_row = 0; starting_row < board.size(); starting_row += 3){
            for(int starting_col = 0; starting_col < board[0].size(); starting_col += 3){
                unordered_set<int> s;
                for(int i = starting_row; i < starting_row + 3; ++i){
                    for(int j = starting_col; j < starting_col + 3; ++j){
                        if(board[i][j] != '.'){
                            if(s.find(board[i][j]) != s.end()){
                                return false;
                            }else{
                                s.insert(board[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return true;


    }
};
