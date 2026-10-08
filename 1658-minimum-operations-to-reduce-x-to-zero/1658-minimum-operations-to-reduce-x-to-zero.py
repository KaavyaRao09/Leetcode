class Solution:
    def minOperations(self, nums, x):
        n = len(nums)
        s = sum(nums)

        t = s - x

        if t == 0:
            return n

        if t < 0:
            return -1

        l = 0
        w = 0
        best = -1

        for r in range(n):
            w += nums[r]

            while w > t:
                w -= nums[l]
                l += 1

            if w == t:
                best = max(best, r - l + 1)

        return -1 if best == -1 else n - best