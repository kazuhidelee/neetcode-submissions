class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        int begin = newInterval[0];
        int end = newInterval[1];
        int curr_begin;
        int curr_end;
        for(auto interval: intervals){
            cout << "---------------" << endl;
            curr_begin = interval[0];
            curr_end = interval[1];
            cout << curr_begin << " " << curr_end << endl;
            cout << begin << " " << end << endl;
            // curr comes before
            if(curr_end < begin){
                cout << "pushing curr" << endl;
                res.push_back({curr_begin, curr_end});
            // curr comes after 
            }else if(end < curr_begin){
                cout << "pushing new" << endl;
                res.push_back({begin, end});
                begin = curr_begin;
                end = curr_end;
            // overlaps
            }else{
                cout << "overlap" << endl;
                begin = min(begin, curr_begin);
                end = max(end, curr_end);
            }
        }
        res.push_back({begin, end});
        return res;
    }
};