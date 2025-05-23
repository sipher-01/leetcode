class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        ans = 0
        count = 0
        discard = float('inf')

        for num in nums:
            ans += max(num,num^k)
            count += 1 if (num<num^k) else 0
            discard = min(discard,abs(num - (num^k)))
        
        return ans if count%2==0 else (ans - discard)
        