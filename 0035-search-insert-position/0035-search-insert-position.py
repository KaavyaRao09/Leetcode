class Solution(object):
    def searchInsert(self, nums: List[int], target: int) -> int:
        # length = len(nums)
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        return len(nums)