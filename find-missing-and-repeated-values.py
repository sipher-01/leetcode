class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        dict = {}
        n = len(grid)
        m = n*n

        for i in range(1,m+1):
            dict[i] = 0
        
        for i in range(n):
            for j in range(n):
                dict[grid[i][j]]+=1
        ans = [0,0]
        for i in range(1,m+1):
            if dict[i]==2:
                ans[0]=i
            elif dict[i]==0:
                ans[1]=i
        
        return ans
        