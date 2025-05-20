class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        diff_arr = [0]*(n+1)
        for l,r in queries:
            diff_arr[l] += 1
            diff_arr[r+1] -= 1
        
        for i in range(1,len(diff_arr)):
            diff_arr[i] += diff_arr[i-1] 
        
        for i in range(n):
            if diff_arr[i]<nums[i]:
                return False
        
        return True


        