class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()
        for i in nums:
            s.add(i)
        res = 0
        for num in s:
            if num - 1 not in s:
                counter = 1
                while num + counter in s:
                    counter += 1
                res = max(res, counter)
        return res
