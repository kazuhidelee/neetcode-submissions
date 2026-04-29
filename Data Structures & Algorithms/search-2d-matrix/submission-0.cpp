class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int x = mid / n;
            int y = mid % n;
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};
