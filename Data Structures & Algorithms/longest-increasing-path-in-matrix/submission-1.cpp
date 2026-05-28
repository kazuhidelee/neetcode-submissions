class Solution {
public:
    int dfs(int r, int c, int m, int n, vector<vector<int>>& matrix, vector<vector<int>> &memo){
        if(memo[r][c] != -1) return memo[r][c];
        int curr = matrix[r][c];
        int left = 0;
        int right = 0;
        int up = 0;
        int down = 0;
        if(c - 1 >= 0 && matrix[r][c - 1] > curr){
            left = dfs(r, c - 1, m, n, matrix, memo);
        }
        if(c + 1 < n && matrix[r][c + 1] > curr){
            right = dfs(r, c + 1, m, n, matrix, memo);
        }
        if(r - 1 >= 0 && matrix[r - 1][c] > curr){
            up = dfs(r - 1, c, m, n, matrix, memo);
        }   
        if(r + 1 < m && matrix[r + 1][c] > curr){
            down = dfs(r + 1, c, m, n, matrix, memo);
        }
        
        memo[r][c] = 1 + max({left, right, up, down});
        return memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int max_length = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                max_length = max(max_length, dfs(i, j, m, n, matrix, memo));
            }
        }
        return max_length;
    }
};
