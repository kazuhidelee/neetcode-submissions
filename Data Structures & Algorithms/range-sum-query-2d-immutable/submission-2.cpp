class NumMatrix {
public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix_sum = vector<vector<int>>(
            matrix.size(),
            vector<int>(matrix[0].size(), 0)
        );
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                if(j > 0 && i > 0){
                    prefix_sum[i][j] = matrix[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
                }else if(j > 0){
                    prefix_sum[i][j] = prefix_sum[i][j - 1] + matrix[i][j];
                }else if(i > 0){
                    prefix_sum[i][j] = prefix_sum[i - 1][j] + matrix[i][j];
                }else{
                    prefix_sum[i][j] = matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int the_whole_square = prefix_sum[row2][col2];
        if(row1 > 0 && col1 > 0){
            the_whole_square -= prefix_sum[row1 - 1][col2];
            the_whole_square -= prefix_sum[row2][col1 - 1];
            the_whole_square += prefix_sum[row1 - 1][col1 - 1];
        }else if(row1 > 0){
            the_whole_square -= prefix_sum[row1 - 1][col2];
        }else if(col1 > 0){
            the_whole_square -= prefix_sum[row2][col1 - 1];
        }

        return the_whole_square;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */