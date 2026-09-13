class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(intervals)):
            curr = intervals[i]
            if curr[1] < newInterval[0]:
                res.append(curr)
            elif curr[0] > newInterval[1]:
                res.append(newInterval)
                return res + intervals[i:]
            else:
                newInterval[0] = min(newInterval[0], curr[0])
                newInterval[1] = max(newInterval[1], curr[1])
        res.append(newInterval)    
        return res