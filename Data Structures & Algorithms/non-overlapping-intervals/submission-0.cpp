class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prev_beg = intervals[0][0];
        int prev_end = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); ++i){
            int curr_beg = intervals[i][0];
            int curr_end = intervals[i][1];
            if(curr_beg < prev_end){
                ++count;
                if(prev_end > curr_end){
                    prev_beg = curr_beg;
                    prev_end = curr_end;
                }
            }else{
                prev_beg = curr_beg;
                prev_end = curr_end;
            }
        }
        return count;

    }
};
