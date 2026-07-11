class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;
        for(auto t: trips){
            events.push_back({t[1], t[0]});
            events.push_back({t[2], -t[0]});
        }
        sort(events.begin(), events.end());
        int curr_cap = 0;
        for(auto e: events){
            if(curr_cap + e.second >= 0){
                curr_cap += e.second;
            }
            if(curr_cap > capacity) return false;
        }

        return true;
    }
};