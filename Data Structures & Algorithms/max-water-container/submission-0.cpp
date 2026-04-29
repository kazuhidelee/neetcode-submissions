class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = INT_MIN;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(area, res);
            if(heights[l] < heights[r]){
                ++l;
            }else{
                --r;
            }
        }
        return res;
    }
};
