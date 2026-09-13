class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        begin = newInterval[0]
        end = newInterval[1]
        for i in range(len(intervals)):
            curr = intervals[i]
            if curr[1] < begin:
                res.append(curr)
            elif curr[0] > end:
                res.append([begin, end])
                begin = curr[0]
                end = curr[1]
            else:
                begin = min(begin, curr[0])
                end = max(end, curr[1])
        res.append([begin, end])    
        return res