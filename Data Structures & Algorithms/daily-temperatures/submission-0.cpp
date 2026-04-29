class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for(int i = 0; i < temperatures.size(); ++i){
            while(!s.empty() && temperatures[i] > s.top().first ){
                auto p = s.top();
                s.pop();
                res[p.second] = i - p.second;
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};
