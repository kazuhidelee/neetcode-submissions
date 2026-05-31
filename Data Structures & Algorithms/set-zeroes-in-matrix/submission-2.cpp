class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // 1. Check first row
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }

        // 2. Check first column
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        // 3. Mark using first row/col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 4. Zero inner cells
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 5. Zero first row
        if (firstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // 6. Zero first col
        if (firstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};