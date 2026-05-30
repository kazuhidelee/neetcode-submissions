class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int total = matrix.size() * matrix[0].size();
        vector<int> curr = {0, 0};
        int curr_dir = 0;
        for(int i = 0; i < total; ++i){
            res.push_back(matrix[curr[0]][curr[1]]);
            matrix[curr[0]][curr[1]] = INT_MIN;
            int next_x = curr[0] + dirs[curr_dir][0];
            int next_y = curr[1] + dirs[curr_dir][1];
            if(next_x >= 0 && next_y >= 0 && next_x < matrix.size() && next_y < matrix[0].size() && matrix[next_x][next_y] != INT_MIN){
                curr[0] = next_x;
                curr[1] = next_y;
            }else{
                curr_dir = (curr_dir + 1) % 4;
                next_x = curr[0] + dirs[curr_dir][0];
                next_y = curr[1] + dirs[curr_dir][1];
                curr[0] = next_x;
                curr[1] = next_y;
            }
        }
        return res;
    }
};
