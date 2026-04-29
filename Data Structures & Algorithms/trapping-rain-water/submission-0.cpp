class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL(height.size(), 0);
        vector<int> maxR(height.size(), 0);
        int curr_max = 0;
        for(int i = 0; i < height.size(); ++i){
            maxL[i] = curr_max;
            cout << maxL[i] << " ";
            curr_max = max(curr_max, height[i]);
        }
        cout << "\n";
        curr_max = 0;
        for(int i = height.size() - 1; i >= 0; --i){
            maxR[i] = curr_max;
            cout << maxR[i] << " ";
            curr_max = max(curr_max, height[i]);
        }
        int total = 0;
        for(int i = 0; i < height.size(); ++i){
            int area = min(maxL[i], maxR[i]) - height[i];
            if(area > 0){
                total += area;
            }
        }
        return total;
    }
};
