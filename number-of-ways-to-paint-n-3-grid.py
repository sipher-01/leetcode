class Solution:
    def __init__(self):
        self.colour_string = []
        self.mod = 10**9 + 7
        self.memo = []

    def generateColumn(self,cur_string,prev_char,l,m):
        if l==m:
            self.colour_string.append(cur_string)
            return
        
        for ch in ('R','Y','G'):
            if prev_char == ch:
                continue
            self.generateColumn(cur_string+ch,ch,l+1,m)


    def solve(self,prev_idx,rem_column):
        if rem_column==0:
            return 1
        if self.memo[rem_column][prev_idx]!=-1:
            return self.memo[rem_column][prev_idx]
        prev_column = self.colour_string[prev_idx]
        ways = 0
        for i in range(len(self.colour_string)):
            if i == prev_idx:
                continue
            cur_column = self.colour_string[i]
            valid = True
            for j in range(3):
                if cur_column[j]==prev_column[j]:
                    valid = False
                    break
            if valid:
                ways = (ways + self.solve(i,rem_column-1))%self.mod
        
        self.memo[rem_column][prev_idx] = ways
        return ways

    def numOfWays(self, n: int) -> int:
        #step 1 : generate all row strings
        self.generateColumn("",'#',0,3)

        
        #step 2: find all ways to fill columns with above found column strings
        res = 0
        k = len(self.colour_string)
        self.memo = [[-1]*(k+1) for _ in range(n+1)]

        for i in range(k):

            res = (res + self.solve(i,n-1))%self.mod
        
        return res
        