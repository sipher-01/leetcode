class Solution:
    mod = int(1e9+7)
    def numTilings(self, n: int) -> int:
        if(n==1 or n==2):
            return n
        dp = [0]*1001
        dp[1]=1
        dp[2]=2
        dp[3]=5
        for i in range(4,n+1):
            dp[i] = (2*dp[i-1]%self.mod + dp[i-3]%self.mod)%self.mod
        
        return dp[n]