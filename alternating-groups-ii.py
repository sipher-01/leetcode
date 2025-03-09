class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        l = 0
        ans = 0
        for r in range(1,2*n): 
            if r-l+1>k: l+=1
            if l>=n: break
            if(colors[r%n]==colors[(r-1)%n]):
                l = r
            if r-l+1 == k : ans += 1

        return ans


        