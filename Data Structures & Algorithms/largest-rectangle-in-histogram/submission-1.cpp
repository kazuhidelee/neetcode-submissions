class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int curr_index = s.top();
                cout << curr_index << endl;
                s.pop();
                int height = heights[curr_index];
                int width;
                if(s.empty()){
                    width = i;
                }else{
                    width = i - s.top() - 1;
                }
                cout << height << "; "<< width << endl;
                res = max(res, height * width);
            }
            s.push(i);
        }
        return res;
    }
};
