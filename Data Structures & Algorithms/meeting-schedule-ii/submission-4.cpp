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
        vector<int> ending;
        for(Interval i: intervals){
            start.push_back(i.start);
            ending.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());
        int ans = 0;
        int res = 0;
        int i = 0;
        int j = 0;
        while(i < start.size() && j < ending.size()){
            if(start[i] < ending[j]){
                res++;
                ++i;
            }else{
                res--;
                ++j;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
