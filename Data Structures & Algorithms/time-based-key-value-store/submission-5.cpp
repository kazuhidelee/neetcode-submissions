class TimeMap {
private:
    // for storing key-value pairs
    unordered_map<string, vector<pair<string, int>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key)){
            return "";
        }
        vector<pair<string, int>> range = m[key];
        int l = 0;
        int r = range.size() - 1;
        int index = -1;
        while(l <= r){
            int m = (l + r)/2;
            int t = range[m].second;
            if(t > timestamp){
                r = m - 1;
            }else{
                index = m;
                l = m + 1;
            }
        }
        if(index == -1){
            return "";
        }
        return range[r].first;
    }
};
