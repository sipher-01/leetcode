class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        maxSum = nums[0]
        sum = nums[0]
        for i in range(1,n):
            sum = max(sum+nums[i],nums[i])
            maxSum = max(maxSum,sum);
        minSum = nums[0]
        sum = nums[0]
        for i in range(1,n):
            sum = min(sum+nums[i],nums[i])
            minSum = min(minSum,sum)
        minSum = abs(minSum)
        if minSum>maxSum:
            return minSum
        return maxSum

        