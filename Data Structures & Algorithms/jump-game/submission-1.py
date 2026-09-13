class Solution:
    def canJump(self, nums: List[int]) -> bool:
        curr_max = 0
        for i in range(len(nums)):
            if curr_max < i:
                return False
            curr_max = max(curr_max, i + nums[i])
        return True
        