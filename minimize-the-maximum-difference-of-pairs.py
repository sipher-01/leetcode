class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        l = 0
        r = nums[-1]
        ans = 0

        def check(x):
            cnt = 0
            i=0
            while i<len(nums)-1:
                if abs(nums[i] - nums[i+1]) <= x:
                    cnt+=1
                    i+=1
                i+=1
            
            if cnt>=p:
                return True
            else:
                return False



        while(l<=r):
            mid = (l+r)//2
            if check(mid):
                ans = mid
                r = mid-1
            else:
                l = mid + 1
        

        return ans
        