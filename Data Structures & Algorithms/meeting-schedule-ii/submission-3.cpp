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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(auto i: intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0;
        int e = 0;
        int res = 0;
        int curr = 0;
        while(s < start.size()){
            if(start[s] < end[e]){
                curr++;
                s++;
            }else{
                curr--;
                e++;
            }
            res = max(curr, res);
        }
        return res;

    }
};
