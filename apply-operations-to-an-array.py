class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                nums[i] *= 2
                nums[i+1] = 0
        n = []
        it = 0
        for i in range(len(nums)):
            if nums[i]==0: it+=1
            else: n.append(nums[i])
        while it>0:
            n.append(0)
            it-=1
        return n
             
