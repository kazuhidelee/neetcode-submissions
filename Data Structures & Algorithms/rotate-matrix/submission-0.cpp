class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //reverse the matrix
        int l = 0;
        int n = matrix.size();
        int h = n - 1;
        while(l <= h){
            for(int i = 0; i < n; ++i){
                swap(matrix[l][i], matrix[h][i]);
            }
            ++l;
            --h;
        }

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
};
