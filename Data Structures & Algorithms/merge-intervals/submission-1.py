class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = []
        prev_begin = intervals[0][0]
        prev_end = intervals[0][1]
        for i in range(1, len(intervals)):
            curr_begin = intervals[i][0]
            curr_end = intervals[i][1]

            if prev_end < curr_begin:
                res.append([prev_begin, prev_end])
                prev_begin = curr_begin
                prev_end = curr_end
            else:
                prev_begin = min(prev_begin, curr_begin)
                prev_end = max(prev_end, curr_end)
        res.append([prev_begin, prev_end])
        return res
        
