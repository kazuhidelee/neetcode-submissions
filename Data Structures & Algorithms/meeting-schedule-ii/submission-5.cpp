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
        vector<int> begins;
        vector<int> ends;
        for(Interval i: intervals){
            begins.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(begins.begin(), begins.end());
        sort(ends.begin(), ends.end());
        int ptr1 = 0;
        int ptr2 = 0;
        int rooms = 0;
        int res = 0;
        while(ptr1 < begins.size() && ptr2 < begins.size()){
            if(begins[ptr1] < ends[ptr2]){
                rooms++;
                ptr1++;
            }else if(begins[ptr1] > ends[ptr2]){
                rooms--;
                ptr2++;
            }else{
                ptr1++;
                ptr2++;
            }

            res = max(res, rooms);
        }
        return res;
    }
};
