from heapq import heappush,heappop

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        m = len(queries)

        queries.sort()

        diff = [0]*(n+1)
        cnt = 0
        j=0
        op = 0

        heap = []
        for i,num in enumerate(nums):
            op += diff[i]
            while j<m and queries[j][0]<=i:
                heappush(heap,-queries[j][1])
                j+=1
            
            while op < num and heap and -heap[0]>=i:
                op += 1
                diff[-heappop(heap) + 1] -=1
            
            if op<num:
                return -1
        return len(heap)


