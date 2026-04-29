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
    struct Compare {
        bool operator()(const Interval& a, const Interval& b) {
            return a.end > b.end;
        }
    };
    

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<Interval, vector<Interval>, Compare> pq;
        size_t day = 0;
        for(auto i: intervals){
            if(!pq.empty() && pq.top().end <= i.start){
                pq.pop();
            }else{
                pq.push(i);
            }
            day = max(day, pq.size());
        }
        return day;

    }
};
