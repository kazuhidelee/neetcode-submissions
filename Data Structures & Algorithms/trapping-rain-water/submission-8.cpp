class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxL = 0;
        int maxR = 0;
        int total = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                maxL = max(maxL, height[l]);
                total += maxL - height[l];
                ++l;
            } else {
                maxR = max(maxR, height[r]);
                total += maxR - height[r];
                --r;
            }
        }

        return total;
    }
};
