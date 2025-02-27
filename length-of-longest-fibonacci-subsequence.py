class Solution:
    def solve(self,j,k,arr,ind)->int:
        target = arr[k]-arr[j]
        if target in ind and ind[target]<j:
            k = ind[target]
            return 1 + self.solve(k,j,arr,ind)
        return 2

    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        ind = {}
        for i in range(len(arr)):
            ind[arr[i]]=i
        res = 0
        for j in range(len(arr)):
            for k in range(j+1,len(arr)):
                length = self.solve(j,k,arr,ind)
                if length>=3:
                    res = max(res,length)
        
        return res
        