class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int total = 0;
        while(l < r){
            if(maxL < maxR){
                ++l;
                maxL = max(height[l], maxL);
                total += maxL - height[l];
            }else{
                --r;
                maxR = max(height[r], maxR);
                total += maxR - height[r];
            }

        }
        return total;
    }
};
