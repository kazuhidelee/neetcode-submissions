class Solution:
    def backtracking(self, nums, index, res, curr):
        res.append(curr.copy())
        for i in range(index, len(nums)):
            if i > index and nums[i] == nums[i - 1]: continue
            curr.append(nums[i])
            self.backtracking(nums, i + 1, res, curr)
            curr.pop()

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        curr = []
        nums.sort()
        self.backtracking(nums, 0, res, curr)
        return res