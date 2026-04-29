class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res;
        vector<int> copy = queries;
        unordered_map<int, int> m;
        sort(intervals.begin(), intervals.end());
        sort(queries.begin(), queries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for(int target: queries){
            while(i < intervals.size() && intervals[i][0] <= target){
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while(!pq.empty() && pq.top().second < target){
                pq.pop();
            }
            
            if(pq.empty()){
                m[target] = -1;
            }else{
                m[target] = pq.top().first;
            }
        }
        for(int q: copy){
            res.push_back(m[q]);
        }
        return res;
    }
};
