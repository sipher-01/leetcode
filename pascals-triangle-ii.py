class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        n = rowIndex + 1
        dp = [1]*n

        for i in range(n-1,-1,-1):
            for j in range(1,i):
                dp[j] = dp[j] + dp[j-1]
        
        return dp

        