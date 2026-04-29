/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval& a, Interval& b){
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0){
            return true;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int prev = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start < prev){
                return false;
            }
            prev = intervals[i].end;
        }
        return true;
    }
};
